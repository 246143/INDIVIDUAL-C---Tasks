#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <random>
#include <chrono>

// ======= Merge Function =======
template <typename T>
void merge(std::vector<T>& data, int left, int mid, int right) {
    std::vector<T> temp;
    int i = left, j = mid;

    while (i < mid && j < right) {
        if (data[i] < data[j])
            temp.push_back(data[i++]);
        else
            temp.push_back(data[j++]);
    }
    while (i < mid) temp.push_back(data[i++]);
    while (j < right) temp.push_back(data[j++]);

    for (int k = 0; k < temp.size(); ++k)
        data[left + k] = temp[k];
}

// ======= Concurrent Merge Sort =======
template <typename T>
void concurrent_merge_sort(std::vector<T>& data, int left, int right, int depth = 0) {
    const int threshold = 10000; // Adaptive switch point
    if (right - left <= 1)
        return;

    int mid = (left + right) / 2;

    if (right - left < threshold || depth > 3) {
        // Sequential sort for small segments or deep recursion
        concurrent_merge_sort(data, left, mid, depth + 1);
        concurrent_merge_sort(data, mid, right, depth + 1);
    } else {
        std::thread t1([&]() { concurrent_merge_sort(data, left, mid, depth + 1); });
        std::thread t2([&]() { concurrent_merge_sort(data, mid, right, depth + 1); });
        t1.join();
        t2.join();
    }

    merge(data, left, mid, right);
}

// ======= Sequential Merge Sort =======
template <typename T>
void sequential_merge_sort(std::vector<T>& data, int left, int right) {
    if (right - left <= 1)
        return;

    int mid = (left + right) / 2;
    sequential_merge_sort(data, left, mid);
    sequential_merge_sort(data, mid, right);
    merge(data, left, mid, right);
}

// ======= Benchmark Helper =======
template <typename SortFunc>
double benchmark(std::vector<int> data, SortFunc sorter, const std::string& label) {
    auto start = std::chrono::high_resolution_clock::now();
    sorter(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;
    std::cout << label << ": " << time.count() << " seconds\n";
    return time.count();
}

// ======= Main =======
int main() {
    const int N = 1'000'000;
    std::vector<int> original(N);

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 1'000'000);
    for (int& x : original)
        x = dist(rng);

    auto data1 = original;
    auto data2 = original;

    benchmark(data1, [](std::vector<int>& data) {
        sequential_merge_sort(data, 0, data.size());
    }, " Sequential Merge Sort");

    benchmark(data2, [](std::vector<int>& data) {
        concurrent_merge_sort(data, 0, data.size());
    }, "Concurrent Merge Sort");

    return 0;
}
