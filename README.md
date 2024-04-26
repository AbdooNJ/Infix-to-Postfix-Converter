# Infix to Postfix Converter

This project is a simple C++ program that converts infix expressions to postfix expressions.

## How to Run

1. Compile the program using a C++ compiler.
2. Create a text file named `input.txt` in the same directory as the compiled program. This file should contain infix expressions, one per line.
3. Run the compiled program. The program will read the infix expressions from `input.txt`, convert them to postfix, and print the postfix expressions to the console.

## Functionality

The program uses a stack to hold operators and parentheses during the conversion process. It determines the precedence of operators using the `OpPriorty` function. The `InToPost` function performs the actual conversion from infix to postfix.


