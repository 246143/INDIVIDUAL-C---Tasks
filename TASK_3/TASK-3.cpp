#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <atomic>
#include <stdexcept>

// Thread Pool with priority and exception support
class ThreadPool {
public:
    ThreadPool(size_t num_threads) : stop(false) {
        for (size_t i = 0; i < num_threads; ++i)
            workers.emplace_back(&ThreadPool::worker_thread, this);
    }

    ~ThreadPool() {
        stop = true;
        cv.notify_all();
        for (auto& t : workers) t.join();
    }

    // Submit task with a priority
    template<typename F, typename... Args>
    auto submit(int priority, F&& f, Args&&... args)
        -> std::future<decltype(f(args...))> {
        
        using RetType = decltype(f(args...));
        auto task_ptr = std::make_shared<std::packaged_task<RetType()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

        Task new_task;
        new_task.priority = priority;
        new_task.func = [task_ptr]() { (*task_ptr)(); };

        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            tasks.push(new_task);
        }

        cv.notify_one();
        return task_ptr->get_future();
    }

private:
    struct Task {
        int priority;
        std::function<void()> func;
        bool operator<(const Task& other) const {
            return priority < other.priority;  // higher = better
        }
    };

    std::priority_queue<Task> tasks;
    std::vector<std::thread> workers;
    std::mutex queue_mutex;
    std::condition_variable cv;
    std::atomic<bool> stop;

    void worker_thread() {
        while (!stop) {
            Task task;

            {
                std::unique_lock<std::mutex> lock(queue_mutex);
                cv.wait(lock, [this]() { return stop || !tasks.empty(); });

                if (stop && tasks.empty()) return;

                task = tasks.top();
                tasks.pop();
            }

            try {
                task.func();
            } catch (const std::exception& e) {
                std::cerr << "[Thread Error] " << e.what() << "\n";
            }
        }
    }
};

// --- Demo using the advanced thread pool ---
int main() {
    ThreadPool pool(3);

    // Task A (high priority)
    auto futureA = pool.submit(10, [] {
        std::cout << "Task A running (high priority)\n";
        return 100;
    });

    // Task B (lower priority)
    auto futureB = pool.submit(5, [] {
        std::cout << "Task B running (low priority)\n";
        return 200;
    });

    // Task C depends on A and B
    auto futureC = pool.submit(8, [&]() {
        int result = futureA.get() + futureB.get();
        std::cout << "Task C running (depends on A & B), result = " << result << "\n";
        return result;
    });

    // Task D throws exception
    auto futureD = pool.submit(7, [] {
        std::cout << "Task D running (will throw)\n";
        throw std::runtime_error("Oops! Task D failed.");
        return 0;
    });

    try {
        futureD.get();
    } catch (const std::exception& e) {
        std::cout << "Caught exception from Task D: " << e.what() << "\n";
    }

    
    futureC.get();

    return 0;
}
