# Concurrent Merge Sort Benchmark

This C++ program demonstrates and compares **Sequential Merge Sort** and **Concurrent Merge Sort** using `std::thread`. The purpose is to show performance improvement with multithreading on large datasets.



# Features

- Templated Merge Sort (works with any comparable data type)
- Sequential vs Concurrent execution
- Benchmarking using high-resolution clock
- Multithreading with depth and size threshold control


# How It Works

1. **Merge Sort** is a divide-and-conquer sorting algorithm.
2. For the concurrent version:
   - If the array segment is large enough and recursion depth is low, it spawns new threads.
   - Otherwise, it falls back to sequential sorting.
3. The sorting time is measured using `std::chrono`.




# How to compile:
we can save it by 
   .cpp format
and Run it in the platform that we are going to use.

# How to Run (For Assessment Purpose)

1. Go to [Online Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Copy the code into the editor
3. Click *Run*


Example output:

 Sequential Merge Sort: 1.52 seconds
Concurrent Merge Sort: 0.89 seconds




Here we can keep the threshold value as our convivenet based on the problem statement

- Adjust the threshold (`threshold = 10000`) or depth (`depth > 3`) to optimize for your CPU's thread count.
- Works best on systems with multiple cores.




# Example Result

Sorting 1 million random integers:
- Sequential: ~1.5 seconds
- Concurrent: ~0.9 seconds (on quad-core)

