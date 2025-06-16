#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <queue>
#include <chrono>
#include <memory>

using namespace std;

// Lock-Free Atomic Shared Pointer

template <typename T>
class AtomicSharedPtr {
private:
    struct ControlBlock {
        T* ptr;
        std::atomic<size_t> ref_count;

        ControlBlock(T* p) : ptr(p), ref_count(1) {}
    };

    ControlBlock* control;

public:
    AtomicSharedPtr(T* p = nullptr) {
        if (p)
            control = new ControlBlock(p);
        else
            control = nullptr;
    }

    AtomicSharedPtr(const AtomicSharedPtr& other) {
        control = other.control;
        if (control)
            control->ref_count.fetch_add(1, std::memory_order_relaxed);
    }

    AtomicSharedPtr& operator=(const AtomicSharedPtr& other) {
        if (this != &other) {
            release();
            control = other.control;
            if (control)
                control->ref_count.fetch_add(1, std::memory_order_relaxed);
        }
        return *this;
    }

    ~AtomicSharedPtr() {
        release();
    }

    void release() {
        if (control && control->ref_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete control->ptr;
            delete control;
        }
    }

    T* get() const {
        return control ? control->ptr : nullptr;
    }

    T& operator*() const { return *get(); }
    T* operator->() const { return get(); }
};

// Stress Test for AtomicSharedPtr

void stress_test_atomic_shared_ptr() {
    AtomicSharedPtr<int> ptr(new int(42));
    const int num_threads = 8;
    const int num_iterations = 100000;

    auto task = [ptr]() {
        for (int i = 0; i < num_iterations; ++i) {
            AtomicSharedPtr<int> local = ptr; // copy
            int value = *local;
            if (value != 42) {
                std::cerr << "Incorrect value accessed!\n";
            }
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i)
        threads.emplace_back(task);
    for (auto& t : threads)
        t.join();

    std::cout << "AtomicSharedPtr stress test passed.\n";
}

// Benchmark Against std::shared_ptr

void benchmark() {
    const int num_threads = 8;
    const int num_iterations = 100000;

    auto time_test = [&](auto create_ptr, const std::string& label) {
        auto start = std::chrono::high_resolution_clock::now();

        auto shared = create_ptr();
        auto task = [shared, create_ptr]() {
            for (int i = 0; i < num_iterations; ++i) {
                auto local = shared;
                int value = *local;
            }
        };

        std::vector<std::thread> threads;
        for (int i = 0; i < num_threads; ++i)
            threads.emplace_back(task);
        for (auto& t : threads)
            t.join();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << label << ": " << elapsed.count() << " seconds\n";
    };

    time_test([]() { return AtomicSharedPtr<int>(new int(42)); }, "🔧 AtomicSharedPtr");
    time_test([]() { return std::shared_ptr<int>(new int(42)); }, "🔗 std::shared_ptr");
}


// Main Function

int main() {
    std::cout << "---- Running Stress Test ----\n";
    stress_test_atomic_shared_ptr();

    std::cout << "\n---- Running Benchmark ----\n";
    benchmark();

    return 0;
}
