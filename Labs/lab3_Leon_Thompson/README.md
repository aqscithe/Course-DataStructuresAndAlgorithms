# COSC 2436 Programming Fundamentals III

**Instructor:** Kathryn Rehfield  
**Lab:** 3 – Linked Lists  
**Due Date:** 04/21/24

## Assignment Description

You will write a program to process the lines in a text file using a linked list ADT and raw pointers.

### Node Class

You will create a class `Node` with the following private data attributes:

- `category` – the category of the line
- `line` – line from a file (string)
- `next` – raw pointer to a `Node`

Put your class definition in a header file and the implementation of the methods in a .cpp file. Follow the style used in the book of having a `#include` for the implementation file at the bottom of the header file.

You will have the following public methods:

- Accessors and mutators for each attribute
- Constructor that initializes the attributes to nulls (empty string or nullptr for the pointer)
- Destructor

### LinkedList Class

You will create a class `LinkedList` with the following private data attributes:

- `headPtr` – raw pointer to the head of the list
- `numItems` – number of items in the list

Put your class definition in a header file and the implementation of the methods in a .cpp file. Follow the style used in the book of having a `#include` for the implementation file at the bottom of the header file.

You will have the following public methods (you can have more if you need to):

- Accessor to get the number of items in the list
- Constructor that initializes `numItems` to zero and `headPtr` to nullptr
- Copy constructor
- Add a node – this method will take as input two string values – the category and the line. It will create a node object and set the attributes. Then it will put the node in the linked list in alphabetical order grouped by category. The categories will not be in sorted order – they will be in the order they were encountered in the file, but the lines within each category will be in alphabetical order. You will not add the items then sort them later – you MUST put them in the correct spot one time. You will not use a vector for any of this process - you are to only process your linked list.
- `toVector` – returns a vector with the contents of the list, which will be a string category followed by a string line of text from the file. You will use only the `push_back` method to get the strings into the vector.
- Destructor

### Data File

The data file contains records with two fields – a category and a line of text. Each line of text is categorized into one of an unknown number of categories.

### Client Program

Your program will:

- Ask the user for the file name, open the text file, read each category/line record, and store it into two strings. Make sure the file opened correctly before you start processing it. You do not know how many records are in the file, so your program should read until it gets to the end of the file.
- Invoke the add method on the linked list object, passing the category and line of text for the current record.
- Display the contents of the list (the records that were read from the file). Display the category once with all of the lines in that category indented.
- Use a class method `toVector` that puts all of the category/line pairs into a vector and returns it to the program that will display it.

### Add Method Details

Your add method will create the node, set the values, and put the node in the list at the correct location. The lines of text should be grouped by category and in ascending order within each category. Put the categories into the linked list in the same order they were first encountered in the file. The program will continue to do this until the end of the file has been reached.

### To Summarize

Your client program will do the following:

- Read file name from user.
- Display the category/line pairs from the file using the class method `toVector` to get this information.

### Example Output

**Example 1:**

If the file contains the following:

Name
Clovis Bagwell
Interesting
The quick brown fox jumped over the lazy dog.
Interesting
Shake rattle and roll.
Nonsense
One red bean stuck in the bottom of a tin bowl.
Boring
The sky is blue.
Name
Archibald Beechcroft

Your program should display:

Name
Archibald Beechcroft
Clovis Bagwell
Interesting
Shake rattle and roll.
The quick brown fox jumped over the lazy dog.
Nonsense
One red bean stuck in the bottom of a tin bowl.
Boring
The sky is blue.

**Example 2:**

If the file contains the following:

Name
Clovis Bagwell
Interesting
The quick brown fox jumped over the lazy dog.
Interesting
Shake rattle and roll.
Name
Archibald Beechcroft

Your program should display:

Name
Archibald Beechcroft
Clovis Bagwell
Interesting
Shake rattle and roll.
The quick brown fox jumped over the lazy dog.


### Lab Grading Points

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

## Submission Requirements

Submit the following:

- All program source and header files compressed into a zip file. Do not include any executable or project files – only .h and .cpp files.
- Name your zip file “lab3_Firstname_Lastname”. You decide what to name the other files.