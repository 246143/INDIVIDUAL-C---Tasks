#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

// Templated Matrix class supporting addition, subtraction, multiplication, and I/O
template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;  // 2D vector to store matrix elements
    size_t rows, cols;                 // Number of rows and columns

public:
    
    Matrix(size_t r, size_t c, T val = T()) : rows(r), cols(c), data(r, std::vector<T>(c, val)) {}

    // Constructor from 2D vector with validation
    Matrix(const std::vector<std::vector<T>>& d) {
        if (d.empty() || d[0].empty()) throw std::invalid_argument("Matrix dimensions cannot be zero.");
        rows = d.size();
        cols = d[0].size();
        for (const auto& row : d)
            if (row.size() != cols)
                throw std::invalid_argument("Inconsistent row sizes.");
        data = d;
    }

    // Accessor methods for row and column count
    size_t rowCount() const { return rows; }
    size_t colCount() const { return cols; }


    std::vector<T>& operator[](size_t i) { return data[i]; }
    const std::vector<T>& operator[](size_t i) const { return data[i]; }

    // Overloaded + operator for matrix addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrix sizes must match for addition.");
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result[i][j] = data[i][j] + other[i][j];
        return result;
    }

    // Overloaded - operator for matrix subtraction
    Matrix<T> operator-(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrix sizes must match for subtraction.");
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result[i][j] = data[i][j] - other[i][j];
        return result;
    }

    // Overloaded * operator for matrix multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw std::invalid_argument("Inner dimensions must match for multiplication.");
        Matrix<T> result(rows, other.cols, T());
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j)
                for (size_t k = 0; k < cols; ++k)
                    result[i][j] += data[i][k] * other[k][j]; // Matrix multiplication logic
        return result;
    }

    // Overloaded << operator to print matrix
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
        for (const auto& row : mat.data) {
            for (const auto& val : row)
                os << std::setw(6) << val << " "; // format for alignment
            os << '\n';
        }
        return os;
    }
};

int main() {
    try {
    
        Matrix<int> A({
            {1, 2},
            {3, 4}
        });

     
        Matrix<int> B({
            {5, 6},
            {7, 8}
        });

        
        Matrix<int> C({
            {4, 2, 3},
            {8, 4, 6}
        });

        
        std::cout << "Matrix A:\n" << A;

        std::cout << "Matrix B:\n" << B;

      
        std::cout << "\nA + B:\n" << (A + B);
\
        std::cout << "A - B:\n" << (A - B);

    
        std::cout << "A * B:\n" << (A * B);

        std::cout << "\nMatrix C:\n" << C;


        std::cout << "A * C:\n" << (A * C);

        // Invalid multiplication: C * B (2x3 * 2x2 -> inner dimensions mismatch)
        std::cout << "C * B (invalid):\n";
        Matrix<int> invalid = C * B;                           // This will throw exception
        std::cout << invalid;                                   // Won’t be reached
    } catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
