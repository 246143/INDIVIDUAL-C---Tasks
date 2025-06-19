
# Numerical Integration in C++

This program performs numerical integration of the function **f(x) = x²** over a given interval using two popular methods:
- *Trapezoidal Rule*
- *Simpson's Rule*

Description:

#rapezoidal Rule
Approximates the integral by summing trapezoidal areas under the curve.
# Simpson's Rule
Uses a weighted sum to provide a more accurate estimate.
#Error Calculation
Compares each result with the approximate exact value 1.71828.
Displays the difference to highlight accuracy.


# Function Being Integrated
f(x) = x²

# Interval of Integration
From **a = 0** to **b = 3**

# Number of Intervals
**n = 10** (Note: Simpson’s Rule requires an even number of intervals. If `n` is odd, it will be incremented by 1 automatically.)


# Exact Value
The exact integral of x² from 0 to 3 is **9.0**.

# How it works

sum = (f(a) + f(b)) / 2 + f(x₁) + f(x₂) + ... + f(xₙ₋₁)
result = h * sum






# How to compile:
we can save it by 
   .cpp format
and Run it in the platform that we are going to use.

# How to Run (For Assessment Purpose)

1. Go to [Online Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Copy the code into the editor
3. Click *Run*



## Output Example
```
Numerical Integration of f(x) = x^2 from 0 to 3
Using 10 intervals:
Trapezoidal Rule Result = 9.135000 (Error = 0.135000)
Simpson's Rule Result   = 9.000000 (Error = 0.000000)
Exact Result            = 9.000000
```

Concepts Demonstrated:


Numerical approximation techniques.

Error analysis.

Precision formatting with iomanip.

Function abstraction in C++.



