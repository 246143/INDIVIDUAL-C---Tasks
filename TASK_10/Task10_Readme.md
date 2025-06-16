
# Monte Carlo Pi Estimation in C++

This program estimates the value of **π (Pi)** using the **Monte Carlo simulation method**.

Description:


# How It Works

- Random points are generated within the unit square [0, 1] x [0, 1].
- The number of points that fall inside the unit quarter-circle is counted.
- The ratio of the number of points inside the circle to the total number of points is used to estimate Pi:

```
Estimated Pi = 4 × (Points Inside Circle / Total Points)
```

# Key Concepts

- *Random number generation* `using `rand()`
- *Uniform distribution* in 2D square
- *Circle equation*: A point (x, y) is inside the circle if `x² + y² ≤ 1`



# How to compile:
we can save it by 
   .cpp format
and Run it in the platform that we are going to use.

# How to Run (For Assessment Purpose)

1. Go to [Online Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Copy the code into the editor
3. Click *Run*


# Example Output



Monte Carlo Pi Estimation:
---------------------------
Samples: 100 -> Estimated Pi: 3
Samples: 500 -> Estimated Pi: 3.184
Samples: 1030 -> Estimated Pi: 3.09515
Samples: 1400 -> Estimated Pi: 3.15143
Samples: 2480 -> Estimated Pi: 3.16613


# Notes

- Accuracy improves with a higher number of samples.
- The randomness is seeded using `srand(time(0))` to get different results on each run.
