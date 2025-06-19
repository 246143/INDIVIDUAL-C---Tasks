
# Polynomial Arithmetic and Root Finding

This project implements a basic `Polynomial` class in C++ that supports common arithmetic operations and root finding using the Newton-Raphson method.

Description:


# Features

-  *Display* a polynomial expression
- *Addition*, ➖ *Subtraction*, ✖️ *Multiplication* of polynomials
-  *Evaluate*the polynomial for a given `x`
-  *Compute Derivative*
-  *Find roots*using Newton-Raphson method

# Implementation Overview

x_new = x - f(x) / f'(x)

# Polynomial Class

```cpp
class Polynomial {
    vector<double> coeffs;
    ...
};
```

# Key Methods

- `display()` - Prints the polynomial expression in standard format.
- `evaluate(x)` - Evaluates the polynomial at a given `x`.
- `derivative()` - Returns a polynomial representing the derivative.
- `add()`, `subtract()`, `multiply()` - Standard polynomial arithmetic.
- `findRoot(double guess)` - Uses Newton-Raphson method to find a root.


# How to Compile:

Save it with a `.cpp` extension and compile with a C++11 or higher compiler.



# How to Run (For Assessment Purpose)

1. Go to [Online Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Copy the code into the editor
3. Click *Run*


Example Output:
Given Polynomial: 1x^3 +4x^2 -10

Polynomial + (x^2 + 2): 1x^3 +5x^2 -8
Polynomial - (x^2 + 2): 1x^3 +3x^2 -12
Polynomial * (x^2 + 2): 1x^5 +4x^4 +2x^3 -2x^2 -20

Found root near 1.5: x = 1.36523
