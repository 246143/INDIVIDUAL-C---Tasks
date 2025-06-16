#include <iostream>
#include <cmath>
#include <iomanip>

// Function to integrate: f(x) = x^2
double f(double x) {
    return x * x;
}

// Trapezoidal Rule
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

// Simpson's Rule
double simpsons(double a, double b, int n) {
    if (n % 2 != 0) {
        std::cout << "Simpson's rule requires even number of intervals. Increasing n by 1.\n";
        n++;  // make even
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    return (h / 3) * sum;
}

int main() {
    double a = 0, b = 3;    // Integration limits
    int n = 10;             // Number of intervals
    double exact = 9.0;     // Known result of ∫ x^2 dx from 0 to 3

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Numerical Integration of f(x) = x^2 from " << a << " to " << b << "\n";
    std::cout << "Using " << n << " intervals:\n";

    double trap = trapezoidal(a, b, n);
    double simp = simpsons(a, b, n);

    std::cout << "Trapezoidal Rule Result = " << trap << " (Error = " << std::abs(trap - exact) << ")\n";
    std::cout << "Simpson's Rule Result   = " << simp << " (Error = " << std::abs(simp - exact) << ")\n";
    std::cout << "Exact Result            = " << exact << "\n";

    return 0;
}
