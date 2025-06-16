#include <iostream>
#include <cmath>
#include <cassert>

                                                                 // Simple templated Vector class
template<typename T>
class Vector3 {
public:
    T x, y, z;

                                                                         // Default constructor
    Vector3() : x(0), y(0), z(0) {}

    // Parameterized constructor
    Vector3(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}

                                                                               // Vector addition
    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

                                                                               // Scalar multiplication
    Vector3 operator*(T scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }
  
                                                                                         // Dot product
    T dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product
    Vector3 cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Normalize the vector
    Vector3 normalize() const {
        T len = std::sqrt(x * x + y * y + z * z);
        assert(len != 0);
        return Vector3(x / len, y / len, z / len);
    }

    // Print vector
    void print(const std::string& name = "Vector") const {
        std::cout << name << " = (" << x << ", " << y << ", " << z << ")\n";
    }
};

// Main to demonstrate usage
int main() {
    Vector3<float> a(1.0f, 5.0f, 3.0f);
    Vector3<float> b(7.0f, 4.0f, 8.0f);

    Vector3<float> sum = a + b;
    Vector3<float> scaled = a * 2.0f;
    float dot = a.dot(b);
    Vector3<float> cross = a.cross(b);
    Vector3<float> norm = a.normalize();

    sum.print("a + b");
    scaled.print("a * 2");
    std::cout << "a . b = " << dot << "\n";
    cross.print("a x b");
    norm.print("normalized a");

    return 0;
}
