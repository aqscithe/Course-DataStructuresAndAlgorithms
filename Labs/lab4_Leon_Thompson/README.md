# COSC 2436 Programming Fundamentals III

**Instructor:** Kathryn Rehfield  
**Lab:** 4 – Binary Trees  
**Due Date:** 05/11/24

## Assignment Description

You will create a class for `EmployeeInfo` that contains:

- `Employee ID Number` – `int`
- `Employee Name` – `string`

Implement a binary search tree whose nodes hold an instance of your `EmployeeInfo` class. The nodes should be sorted on the `Employee ID Number`. You will have a binary search tree class header and implementation file.

### Test Data

You can write your `main` to use the following information to test your tree:

| Employee ID Number | Employee Name         |
|--------------------|------------------------|
| 6702               | James B W Bevis        |
| 1255               | Romney Wordsworth      |
| 1071               | Revis Jacara           |
| 2390               | Clegg Forbes           |
| 1558               | Kalin Tros             |
| 7406               | Archibald Beechcroft   |
| 7562               | Penthor Mul            |
| 3004               | Bartlet Finchley       |
| 4922               | Latham Bine            |
| 8483               | Jeff Myrtlebank        |

### Main Function Requirements

Your `main` will have one binary search tree object and all of the operations on the binary search tree will be class methods. You will also offer the following options to the user:

- Search for an ID
- Display the tree
- Add a new employee
- Remove an employee

## Submission Requirements

Submit the following:

- All program source and header files compressed into a zip file. Name your zip file “lab4_Firstname_Lastname”. You decide what to name the other files.

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