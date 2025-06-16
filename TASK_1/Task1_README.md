
# Templated Matrix Class in C++ #

Description :

This project provides a simple yet powerful *generic Matrix class* in C++ using templates. It supports:

- Matrix creation
- Addition, subtraction, and multiplication
- I/O operations (stream output)
- Exception handling for invalid operations
.


# How to compile:
we can save it by 
   .cpp format
and Run it in the platform that we are going to use.

# How to Run (For Assessment Purpose)
 
1. Go to [Online Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Type code into the editor
3. Click *Run*
 




---

# Features

- Templated Class – Works with any type (e.g., `int`, `float`, `double`)
-  Addition– Element-wise matrix addition
-  Subtraction– Element-wise matrix subtraction
- Multiplication– Matrix product (inner dimensions must match)
- Formatted Output – Neatly formatted matrix printing using `operator<<`
- Error Handling– Throws `std::invalid_argument` for invalid operations

---


# Valid Operations

A + B;   // Matrix addition
A - B;   // Matrix subtraction
A * B;   // 2x2 * 2x2 = 2x2
A * C;   // 2x2 * 2x3 = 2x3
```

Matrix A:
     1      2 
     3      4 
Matrix B:
     5      6 
     7      8 

A + B:
     6      8 
    10     12 
A - B:
    -4     -4 
    -4     -4 
A * B:
    19     22 
    43     50 

Matrix C:
     4      2      3 
     8      4      6 
A * C:
ERROR!
    20     10     15 
    44     22     33 
C * B (invalid):
Error: Inner dimensions must match for multiplication.





# Notes

- Ensure all matrices involved in arithmetic operations have compatible dimensions.
- Use `std::vector<std::vector<T>>` to initialize matrices easily.
- Change the template type (`int`, `float`, etc.) as needed.

---

