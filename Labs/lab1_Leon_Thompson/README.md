# COSC 2436 Programming Fundamentals III

**Instructor:** Kathryn Rehfield  
**Lab:** 1 – Arrays and Recursion  
**Due Date:** 02/25/24

## Assignment Description

You will use the array bag code that we reviewed in the textbook. This code is provided with this assignment. In this code, I have added one new method to the class for you to use as a guide. You should remove all traces of the “doSomething” method in all the files before you submit your assignment.

### New Methods to Implement

You will write 3 new methods in the `ArrayBag` class:

1. **bubbleSort** - A method to sort the array in ascending order using bubble sort.
2. **binarySearchIterative** - An iterative version of the binary search.
3. **binarySearchRecursive** - A recursive version of the binary search. (You should use a helper method that calls the recursive method so the client code does not have to provide the extra parameters. Client calls to both of the search methods should be identical other than the method name.)

### Client Code Requirements

Your client code should:

- Load your bag with some initial values, but do not fill it completely.
- Provide the user with the following options:
  - Display the contents of the bag using the class method `toVector`.
  - Add values to the bag.
  - Remove values from the bag.
  - Sort the bag.
  - Search for a value using their choice of either the iterative search or the recursive search. Both need to be tested.
- Allow the user to keep performing these actions until they are done.
- Not automatically sort the bag if the user chooses to search. Your program should inform the user that they must first sort the bag before they can search. You must devise a method to detect programmatically if the array has not been sorted.
- Ensure each value in your array is unique - no duplicate values.
- Use a template class for the array elements, allowing the client code to process a bag holding any data type.

### Program Design

- The user interface should be clear and easy to use. A menu-driven program is recommended.
- Write your client code in a modular, structured fashion.
- Ensure proper input validation where appropriate.
- Your program should be robust and well-documented, reflecting the skills of a third-semester programming student.

## Submission Requirements

Submit the following:

- All program source and header files compressed into a zip file (.zip). Name your zip file “lab1_Firstname_Lastname”. You decide what to name the other files. Do not include .exe files.

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

- **Leaving a loop (or iteration), function, or other construct prematurely:** You will NEVER use `break`, `exit`, `return`, `pass`, `continue`, or anything similar unless it is part of the structure (e.g., a `switch` statement).
- **Intentional Recursion:** You will NEVER have a function call itself unless it is intentional recursion.
- **Global Variables:** You will NEVER use global variables. However, global constants are allowed if appropriate and used properly.
- **Single Return Statement:** You will have only one return statement in a function. (Exception: Multiple return statements may be necessary in a recursive function.)
- **Infinite Loops:** You will NEVER intentionally write an infinite loop and then break out of it.

Make sure your code adheres to these guidelines to avoid penalties.