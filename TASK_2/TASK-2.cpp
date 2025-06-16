#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <string_view>
#include <vector>

class ExpressionEvaluator {
    std::string_view expr;
    size_t pos = 0;

    
    char peek() {
        while (pos < expr.size() && std::isspace(expr[pos])) ++pos;
        return pos < expr.size() ? expr[pos] : '\0';
    }

    // Gets the current character and advances the position
    char get() {
        char ch = peek();
        ++pos;
        return ch;
    }

    // Parses a number (integer or floating point)
    double parseNumber() {
        size_t start = pos;
        while (pos < expr.size() && (std::isdigit(expr[pos]) || expr[pos] == '.')) ++pos;
        return std::stod(std::string(expr.substr(start, pos - start)));
    }

    // Parses factors: numbers, parenthesized expressions, or unary minus
    double factor() {
        char ch = peek();
        if (ch == '(') {
            get(); // consume '('
            double val = expression();
            if (get() != ')') throw std::runtime_error("Expected ')'");
            return val;
        } else if (ch == '-') {
            get(); // unary minus
            return -factor();
        } else if (std::isdigit(ch) || ch == '.') {
            return parseNumber();
        }
        throw std::runtime_error("Invalid factor");
    }

    // Parses terms: handles *, /
    double term() {
        double result = factor();
        while (true) {
            char op = peek();
            if (op == '*' || op == '/') {
                get();
                double next = factor();
                if (op == '*') result *= next;
                else {
                    if (next == 0) throw std::runtime_error("Division by zero");
                    result /= next;
                }
            } else break;
        }
        return result;
    }

    double expression() {
        double result = term();
        while (true) {
            char op = peek();
            if (op == '+' || op == '-') {
                get();
                double next = term();
                if (op == '+') result += next;
                else result -= next;
            } else break;
        }
        return result;
    }

public:
    // Public interface to evaluate an expression
    double evaluate(std::string_view input) {
        expr = input;
        pos = 0;
        double result = expression();
        if (peek() != '\0') throw std::runtime_error("Unexpected character at end");
        return result;
    }
};

int main() {
    ExpressionEvaluator evaluator;

    std::vector<std::string> tests = {
        "3 + 5",
        "10 + 2 * 6",
        "100 * (2 + 12) / 14",
        "3 + (4 - 1) * 5",
        "-3 + 2",
        "2 + 3.5 * 2",
        "((1+2)*3)-(4/2)+7"
    };

    for (const auto& expr : tests) {
        try {
            double result = evaluator.evaluate(expr);
            std::cout << "Expression: " << expr << " = " << result << "\n";
        } catch (const std::exception& e) {
            std::cout << "Error in \"" << expr << "\": " << e.what() << "\n";
        }
    }

    return 0;
}
