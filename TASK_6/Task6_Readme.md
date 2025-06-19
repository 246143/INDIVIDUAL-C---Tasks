
#  Work-Stealing Thread Pool in C++

This program demonstrates a **work-stealing thread pool** implementation using C++ threads, mutexes, atomics, and queues.

 
Description:


- A pool of **4 worker threads** and a **single producer thread**.
- Tasks are distributed **round-robin** by the producer into multiple queues.
- Consumers attempt to process from their own queue first.
- If their queue is empty, they attempt to **steal work** from other queues.

---

 Key Features:

- **Multi-queue design**: One task queue per worker.
- **Work-stealing**: Threads can take work from others to avoid idling.
- **Thread-safe operations** with `std::mutex` and `std::lock_guard`.
- Controlled task generation with `std::this_thread::sleep_for`.

---

# Sample Output

[Producer] Task 0 added to queue 0
Task 0 run by thread 136034265765568
[Producer] Task 1 added to queue 1
[Thread 2] Stole task from queue 1
Task 1 run by thread 136034163619520
[Producer] Task 2 added to queue 2
[Thread 3] Stole task from queue 2
Task 2 run by thread 136034248980160
[Producer] Task 3 added to queue 3
[Thread 1] Stole task from queue 3
Task 3 run by thread 136034257372864
[Producer] Task 4 added to queue 0
Task 4 run by thread 136034265765568
[Producer] Task 5 added to queue 1
[Thread 2] Stole task from queue 1
Task 5 run by thread 136034163619520
[Producer] Task 6 added to queue 2
[Thread 3] Stole task from queue 2
Task 6 run by thread 136034248980160
[Producer] Task 7 added to queue 3
[Thread 1] Stole task from queue 3
Task 7 run by thread 136034257372864
[Producer] Task 8 added to queue 0
Task 8 run by thread 136034265765568
[Producer] Task 9 added to queue 1
[Thread 2] Stole task from queue 1
Task 9 run by thread 136034163619520
[Producer] Task 10 added to queue 2
[Thread 3] Stole task from queue 2
Task 10 run by thread 136034248980160
[Producer] Task 11 added to queue 3
[Thread 1] Stole task from queue 3
Task 11 run by thread 136034257372864
[Producer] Task 12 added to queue 0
Task 12 run by thread 136034265765568
[Producer] Task 13 added to queue 1
[Thread 2] Stole task from queue 1
Task 13 run by thread 136034163619520
[Producer] Task 14 added to queue 2
[Thread 3] Stole task from queue 2
Task 14 run by thread 136034248980160
[Producer] Task 15 added to queue 3
[Thread 1] Stole task from queue 3
Task 15 run by thread 136034257372864
[Producer] Task 16 added to queue 0
Task 16 run by thread 136034265765568
[Producer] Task 17 added to queue 1
[Thread 2] Stole task from queue 1
Task 17 run by thread 136034163619520
[Producer] Task 18 added to queue 2
[Thread 3] Stole task from queue 2
Task 18 run by thread 136034248980160
[Producer] Task 19 added to queue 3
[Thread 1] Stole task from queue 3
Task 19 run by thread 136034257372864

 All tasks done in 692 ms.


 # How to Compile:

Save it with a `.cpp` extension and compile with a C++11 or higher compiler.



# How to Run (For Assessment Purpose)

1. Go to [Online Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Copy the code into the e




Concepts we can learn :

- Producer-consumer pattern
- Thread-safe queue operations
- Atomics (`std::atomic<bool>`)
- Work stealing for load balancing

