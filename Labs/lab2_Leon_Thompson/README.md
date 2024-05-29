# COSC 2436 Programming Fundamentals III

**Instructor:** Kathryn Rehfield  
**Lab:** 2 – Prefix Expression Evaluator using a Stack  
**Due Date:** 03/19/24

## Assignment Description

You will write a program to evaluate and display a prefix expression using a stack, not recursion. It is easy to evaluate a prefix expression starting at the end, saving each operand until you encounter an operator, which will operate on the two operands you last encountered (saved).

### Requirements

- Use the stack ADT provided with the assignment. This ADT was covered in Chapter 7. The files are attached to this assignment.
- The expression will contain single integer values and only binary operators +, -, /, *.
- The `main` function should:
  - Ask the user to enter a valid prefix expression.
  - Pass the expression to a function that evaluates and returns the calculated value.
  - Display a message for the user with the result.

**Example:**

- If the user enters `+*234`, the result should be `10`.
- If the user enters `*/638`, the result should be `16`.

### Program Loop

- Use a sentinel-controlled while loop to continue reading and evaluating prefix expressions until the user enters the sentinel value. You decide the sentinel value.

## Submission Requirements

Submit the following:

- All of your program source (.cpp) and header (.h) files compressed into a zip file. Name your zip file “lab2_Firstname_Lastname.zip”. You decide what to name the other files.

## Sample Input and Output

- Input: `+-86*34` 
  - Output: `14`
- Input: `+-*3481`
  - Output: `5`
- Input: `+3*98`
  - Output: `75`
- Input: `/+-*5433+23`
  - Output: `4`

## Lab Grading Points

Labs will be graded on the following criteria:

- **Comments**
  - Program description (comment block at top of program)
  - Function descriptions for every function other than `main()` (including purpose, input, and output)
  - Comments at major algorithm steps (at a minimum)
- **Followed Directions**
- **Correct Output**
- **Structured Program Design**
- **Meaningful Identifier Names**

### Note on Structured Programming

Unstructured programming practices are not allowed. This includes:

- **Leaving a loop (or iteration), function, or other construct prematurely:** You will NEVER use `break`, `exit`, `return`, `pass`, `continue`, or anything similar unless it is part of the structure (e.g., a `case` statement).
- **Intentional Recursion:** You will NEVER have a function call itself unless it is intentional recursion.
- **Global Variables:** You will NEVER use global variables. However, global constants are allowed if appropriate and used properly.
- **Single Return Statement:** You will have only one return statement in a function. (Exception: Multiple return statements may be necessary in a recursive function.)
- **Infinite Loops:** You will NEVER intentionally write an infinite loop and then break out of it.

Make sure your code adheres to these guidelines to avoid penalties.