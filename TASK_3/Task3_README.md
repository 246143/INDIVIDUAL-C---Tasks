
# Advanced C++ Thread Pool with Priority, Dependencies & Exceptions

Description:


This project implements a *modern C++ thread pool* with support for:

- Task priority scheduling
- Task dependencies (via `std::future`)
- Exception handling within tasks
- Safe concurrent execution using `std::mutex`, `std::condition_variable`, and `std::atomic`

It demonstrates how to manage parallel tasks in a robust and structured way — ideal for learning multithreading in C++.

---

# Features

- Priority Queue: Tasks with higher priority run before lower ones
-Dependencies: Tasks can wait for the result of other tasks (via `.get()`)
- Error Propagation: Exceptions in threads are caught and reported
- Multiple Worker Threads: Thread pool with configurable thread count
- Flexible Interface: Submit any callable with arguments using `submit(priority, function, args...)`

---

# Example Tasks in `main()`

# Tasks Submitted

1. Task A: High priority → prints and returns 100
2. Task B: Low priority → prints and returns 200
3. Task C: Medium priority → depends on A & B → adds results and prints
4. Task D: Throws an exception

# Sample Output

```
Task A running (high priority)
Task B running (low priority)
Task D running (will throw)
Caught exception from Task D: Oops! Task D failed.
Task C running (depends on A & B), result = 300
```

---

# How It Works

- A **priority queue** stores tasks based on integer priority (higher = better)
- Each thread waits on a condition variable and picks the next available task
- If a task throws an exception, it's caught and printed from the worker thread
- `std::packaged_task` + `std::future` enables return values and dependencies

  
  # How to compile:
we can save it by 
   .cpp format
and Run it in the platform that we are going to use.

# How to Run (For Assessment Purpose)
 
1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Type code into the editor
3. Click *Run*
 






# Key Concepts :

- Thread creation and joining
- Condition variables for signaling
- Priority queue for task scheduling
- Futures for inter-task communication
- Exception safety in multi-threaded context

---

