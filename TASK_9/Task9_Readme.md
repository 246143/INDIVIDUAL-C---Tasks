
# Vector3 Class in C++

This C++ program defines a simple **templated 3D vector class (`Vector3<T>`)** to perform basic vector operations commonly used in mathematics, physics, and computer graphics.

Description:


## Features

The `Vector3<T>` class provides the following functionalities:

- **Vector Addition (`+`)**  
- **Scalar Multiplication (`*`)**
- **Dot Product**
- **Cross Product**
- **Normalization (Unit Vector)**
- **Formatted Output (Print)**


# How to compile:
we can save it by 
   .cpp format
and Run it in the platform that we are going to use.

# How to Run (For Assessment Purpose)

1. Go to [Online Programiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Copy the code into the editor
3. Click *Run*



# Example Output:
a + b = (8, 9, 11)
a * 2 = (2, 10, 6)
a . b = 51
a x b = (28, 13, -31)
normalized a = (0.169031, 0.845154, 0.507093)




 Note: The normalization uses `assert(len != 0)` to ensure the vector length is not zero.



# Highlights

- Uses **C++ Templates** to support any numeric type (e.g., `float`, `double`, `int`).
- Suitable for basic **3D vector algebra**.
- Great for educational purposes or small-scale geometry simulations.
