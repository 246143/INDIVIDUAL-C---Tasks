
# Simple Arithmetic Expression Evaluator in C++

Description :

This project demonstrates a simple **recursive descent parser** to evaluate arithmetic expressions in C++. It supports:

- Basic arithmetic: `+`, `-`, `*`, `/`
- Parentheses for grouping `()`
- Decimal numbers (e.g., `3.5`, `2.0`)
- Unary minus (e.g., `-3 + 2`)

The evaluator uses a clean and readable structure for better understanding.



# Features

-  Handles operator precedence (multiplication/division before addition/subtraction)
-  Supports parentheses and nested expressions
-  Works with floating-point numbers
-  Provides meaningful error messages (e.g., division by zero, syntax errors)
- Fully self-contained in a single class: `ExpressionEvaluator`



# Example Expressions

The `main()` function tests the evaluator with various expressions:


Expression: 3 + 5              = 8
Expression: 10 + 2 * 6         = 22
Expression: 100 * (2 + 12) / 14 = 100
Expression: 3 + (4 - 1) * 5     = 18
Expression: -3 + 2             = -1
Expression: 2 + 3.5 * 2        = 9
Expression: ((1+2)*3)-(4/2)+7  = 14
```



# How It Works

The evaluator breaks the expression into three levels of grammar:

1. expression: Handles `+` and `-`
2. term: Handles `*` and `/`
3. factor: Handles numbers, parentheses, and unary minus

It uses a pointer (`pos`) to track the current character being processed.

---

# How to compile:

we can save it by 
   .cpp format
and Run it in the platform that we are going to use.

# How to Run (For Assessment Purpose)
 
1. Go to [OnlineProgramiz](https://www.programiz.com/cpp-programming/online-compiler/)
2. Type code into the editor
3. Click *Run*

```



#  Error Handling

The code throws exceptions for:

- Invalid characters or syntax
- Missing parentheses
- Division by zero

These are caught and displayed with informative messages.
