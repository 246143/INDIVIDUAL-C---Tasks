# AtomicSharedPtr Stress Test & Benchmark

This C++ program demonstrates a **custom lock-free atomic shared pointer** (`AtomicSharedPtr`) implementation using atomic reference counting. It compares performance and correctness with the standard `std::shared_ptr` under multithreaded conditions.

Description:


# Features

- Custom smart pointer with manual atomic reference counting
- Stress test for multithreaded safety
- Benchmark vs `std::shared_ptr`
- Demonstrates performance under concurrency

# How It Works

1. `AtomicSharedPtr` manages reference counting manually using atomics.
2. Stress Test:
   - Multiple threads repeatedly copy and access the shared pointer.
   - Validates safety by checking consistent value access.

3. Benchmark:
   - Measures and compares access speed for `AtomicSharedPtr` and `std::shared_ptr`.
   - Uses `std::chrono::high_resolution_clock` for timing.

# How to Compile:

Save it with a `.cpp` extension and compile with a C++11 or higher compiler.



# How to Run (For Assessment Purpose)

1. Go to [Online Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Copy the code into the editor
3. Click *Run*


# Example Output
---- Running Stress Test ----
AtomicSharedPtr stress test passed.

---- Running Benchmark ----
 AtomicSharedPtr: 0.187515 seconds
 std::shared_ptr: 0.112345 seconds





