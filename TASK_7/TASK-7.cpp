#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ----------- Polynomial Class -------------
class Polynomial {
private:
    vector<double> coeffs;                                    // coeffs[i] is coefficient of x^i

public:
    // Constructor
    Polynomial(vector<double> c) {
        coeffs = c;
    }

    // Display the polynomial
    void display() {
        for (int i = coeffs.size() - 1; i >= 0; --i) {
            if (coeffs[i] == 0) continue;
            if (i != coeffs.size() - 1 && coeffs[i] > 0) cout << "+";
            cout << coeffs[i];
            if (i > 0) cout << "x^" << i << " ";
        }
        cout << endl;
    }

    // Evaluate the polynomial at x
    double evaluate(double x) {
        double result = 0;
        for (int i = coeffs.size() - 1; i >= 0; --i) {
            result = result * x + coeffs[i];
        }
        return result;
    }

                                                        // Derivative of the polynomial
    Polynomial derivative() {
        vector<double> deriv;
        for (int i = 1; i < coeffs.size(); ++i) {
            deriv.push_back(i * coeffs[i]);
        }
        return Polynomial(deriv);
    }

                                                                     // Add two polynomials
    Polynomial add(Polynomial& other) {
        int maxSize = max(coeffs.size(), other.coeffs.size());
        vector<double> result(maxSize, 0);
        for (int i = 0; i < maxSize; ++i) {
            if (i < coeffs.size()) result[i] += coeffs[i];
            if (i < other.coeffs.size()) result[i] += other.coeffs[i];
        }
        return Polynomial(result);
    }

                                                                        // Subtract another polynomial
    Polynomial subtract(Polynomial& other) {
        int maxSize = max(coeffs.size(), other.coeffs.size());
        vector<double> result(maxSize, 0);
        for (int i = 0; i < maxSize; ++i) {
            if (i < coeffs.size()) result[i] += coeffs[i];
            if (i < other.coeffs.size()) result[i] -= other.coeffs[i];
        }
        return Polynomial(result);
    }

    // Multiply by another polynomial
    Polynomial multiply(Polynomial& other) {
        vector<double> result(coeffs.size() + other.coeffs.size() - 1, 0);
        for (int i = 0; i < coeffs.size(); ++i) {
            for (int j = 0; j < other.coeffs.size(); ++j) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return Polynomial(result);
    }

    // Newton-Raphson Method for root finding
    double findRoot(double guess) {
        Polynomial derivPoly = derivative();
        const int maxIter = 100;
        const double epsilon = 1e-6;

        for (int i = 0; i < maxIter; ++i) {
            double fx = evaluate(guess);
            double fpx = derivPoly.evaluate(guess);

            if (fabs(fpx) < epsilon) {
                cout << "Derivative too small. Stopping." << endl;
                break;
            }

            double nextGuess = guess - fx / fpx;
            if (fabs(nextGuess - guess) < epsilon) {
                return nextGuess;
            }
            guess = nextGuess;
        }

        return guess; 
    }
};
int main() {]
    vector<double> coeffs = { -10, 0, 4, 1 }; // -10 + 0x + 4x^2 + 1x^3
    Polynomial p(coeffs);

    cout << "Given Polynomial: ";
    p.display();

    // Another polynomial: g(x) = x^2 + 2
    Polynomial p2({2, 0, 1});  // 2 + x^2

    // Addition: p + p2
    Polynomial sum = p.add(p2);
    cout << "\nPolynomial + (x^2 + 2): ";
    sum.display();

    // Subtraction: p - p2
    Polynomial diff = p.subtract(p2);
    cout << "Polynomial - (x^2 + 2): ";
    diff.display();

    // Multiplication: p * p2
    Polynomial mul = p.multiply(p2);
    cout << "Polynomial * (x^2 + 2): ";
    mul.display();

    // Find a root using Newton-Raphson
    double root = p.findRoot(1.5); // Start near the expected root
    cout << "\nFound root near 1.5: x = " << root << endl;

    return 0;
}
