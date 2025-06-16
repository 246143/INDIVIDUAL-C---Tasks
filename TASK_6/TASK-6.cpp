#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <atomic>
#include <chrono>

using namespace std;

const int NUM_WORKERS = 4;
const int NUM_TASKS = 20;                     // num of tasks and workers

struct Task {
    int id;
    void run() const {
        cout << "Task " << id << " run by thread " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(100));                                              // Simulated work
    }
};

class TaskQueue {
public:
    queue<Task> q;
    mutex mtx;

    bool try_pop(Task &task) {
        lock_guard<mutex> lock(mtx);
        if (q.empty()) return false;
        task = q.front();
        q.pop();
        return true;
    }

    void push(Task task) {
        lock_guard<mutex> lock(mtx);
        q.push(task);
    }

    bool empty() {
        lock_guard<mutex> lock(mtx);
        return q.empty();
    }
};

vector<TaskQueue> queues(NUM_WORKERS);
atomic<bool> done_producing(false);

void producer() {
    for (int i = 0; i < NUM_TASKS; ++i) {
        Task task{ i };
        int target = i % NUM_WORKERS;                                // Round-robin to each queue
        queues[target].push(task);
        cout << "[Producer] Task " << i << " added to queue " << target << endl;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
    done_producing = true;
}

void consumer(int id) {
    Task task;
    while (!done_producing || !queues[id].empty()) {
                                                                     // Try to pop from own queue
        if (queues[id].try_pop(task)) {
            task.run();
        } else {
                                                                                 // Try stealing from other queues
            for (int i = 0; i < NUM_WORKERS; ++i) {
                if (i == id) continue;
                if (queues[i].try_pop(task)) {
                    cout << "[Thread " << id << "] Stole task from queue " << i << endl;
                    task.run();
                    break;
                }
            }
            this_thread::sleep_for(chrono::milliseconds(10));
        }
    }
}

int main() {
    auto start = chrono::steady_clock::now();

    thread prod(producer);

    vector<thread> workers;
    for (int i = 0; i < NUM_WORKERS; ++i)
        workers.emplace_back(consumer, i);

    prod.join();
    for (auto &t : workers)
        t.join();

    auto end = chrono::steady_clock::now();
    cout << "\n✅ All tasks done in "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms.\n";
}
