/*
-------------------------------------------------------------------------
Name:			Leon Thompson
Date:			03/19/2024
Lab #:			2
Status: 		Completed
-------------------------------------------------------------------------
Description
	This program acts as a prefix expression evaluator, allowing the user
    to input expressions and see the calculated result.
-------------------------------------------------------------------------
*/


#include <iostream>
#include <string>
#include "ArrayStack.h"


void prefixExpSelection();
int processPrefixExp(const std::string&);
int performOperation(int, int, char);
std::string reverseString(const std::string&);
void greetUser();
void displayHeader();
void displayOptions();
char getCharData(std::string);
std::string getStringData(std::string);
void clearCin();


int main()
{
    // Declare main variables
    char optionSelection;
    bool showMainMenu = true;

    greetUser();

    // Main Menu Loop
    while(showMainMenu)
    {
        displayOptions();
        optionSelection = getCharData("What would you like to do next? ");

        switch (optionSelection)
        {
            case 'P':
            {
                prefixExpSelection();
                break;
            }

            case 'Q':
            case 'X':
            {
                showMainMenu = false;
                break;
            }
            
            default:
            {
                break;
            }
        } // end switch
    } // end while

    std::cout << "I hope you've endjoyed your time using the Everything Calculator." << std::endl;

    return 0;
} // end main



/****************************************************************/
/* Function:   prefixExpSelection
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function prompts the user for a prefix
    expression and runs related the necessary code to solve 
    required to solve it.
/****************************************************************/
void prefixExpSelection()
{
    // Declare function variables
    std::string expression;
    std::string reversed;
    int result;

    expression = getStringData("Enter a prefix expression: ");

    // Prefix evaluation is more intuitive using stack if read from right to left
    reversed = reverseString(expression);
    result = processPrefixExp(reversed);

    // Print Expression and Result
    std::cout << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << std::endl;
    std::cout << "EXPRESSION: " << expression << " | RESULT: " << result << std::endl;
    std::cout << std::endl;
    std::cout << "**********************************" << std::endl;

} // end prefixExpSelection



/****************************************************************/
/* Function:   processPrefixExp
/* Inputs:     const std::string& expression
/* Outputs:    int operands.peek()
/* Purpose:    This function loops through the chars in the 
    expression, placing operands onto the array stack, performing
    operations when an operator is found, removing old operands
    and pushing the resulting value onto the stack.
/****************************************************************/
int processPrefixExp(const std::string& expression)
{
    // Declare function variables
    ArrayStack<int> operands;

    // Loop through characters in expression
    for (int ch = 0; ch < expression.length(); ch++)
    {
        char character = expression[ch];

        // Check if character is a number
        if ( std::isdigit(character) )
        {
            // Convert operand to integer
            int digit = character - '0';

            operands.push(digit);
        }
        // Otherwise char must be operator(we assume exp is valid)
        else
        {
            // Grab operands and pop them from the stack
            int operand1 = operands.peek();
            operands.pop();
            int operand2 = operands.peek();
            operands.pop();

            // Run operation on operands and push result onto stack
            int result = performOperation(operand1, operand2, character);
            operands.push(result);
        } // end if
    } // end for
    
    return operands.peek();
} // end processPrefixExp



/****************************************************************/
/* Function:   performOperation
/* Inputs:     int operand1, int operand2, char operator_
/* Outputs:    int result
/* Purpose:    This function takes the operands and operator,
    finds the appropriate math calculation and returns the result
    of the operation.
/****************************************************************/
int performOperation(int operand1, int operand2, char operator_)
{
    // Declare result variable
    int result;

    // Switch to find correct math operation
    switch (operator_)
    {
        case '+':
        {
            result = operand1 + operand2;
            break;
        }

        case '-':
        {
            result = operand1 - operand2;
            break;
        }

        case '*':
        {
            result = operand1 * operand2;
            break;
        }

        case '/':
        {
            // No division by zero
            if(operand2 != 0)
            {
                result = operand1 / operand2;
            }
            break;
        }

        case '%':
        {
            // No division by zero
            if(operand2 != 0)
            {
                result = operand1 % operand2;
            }
            break;
        }

        default:
            break;
    } // end switch

    return result;
} // end performOperation



/****************************************************************/
/* Function:   reverseString
/* Inputs:     const std::string& word
/* Outputs:    std::string
/* Purpose:    This function uses recursion to take a string and
    return it in the reverse order
/****************************************************************/
std::string reverseString(const std::string& word) 
{
    // Base case encountered when string is empty
    // Returns an empty string
    if(word.empty()) 
    {
        return "";
    }
    else 
    {
        // Recursive case: Call the function with the substring missing the first character
        // and then append the first character of the current string to the result
        return reverseString(word.substr(1)) + word[0];
    } // end if
} // end reverseString


/****************************************************************/
/* Function:   greetUser
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function greets the user upon app load
/****************************************************************/
void greetUser()
{
	std::cout << "WELCOME TO THE EVERYTHING CALCULATOR" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "Due to some technical difficulties and widespread political unrest we can only evaluate prefix expressions but stay tuned... " << std::endl;
    std::cout << "Here is how it works:" << std::endl;
	std::cout << "\tEnter a string that represents a valid prefix expression. Ex: /+-*5433+23 " << std::endl;
    std::cout << "\tNote that our current overlording project manager has not \
        provided us the time to implement proper validation so we hope your expression is correct." << std::endl;
	std::cout << "\tPress enter" << std::endl;
	std::cout << "\tWait as our state-of-the-art tech evaluates your expression in a fraction of a second." << std::endl;
	std::cout << "\tWant to solve more expressions. No problem. The Everything \
        Calculator can solve as many as you would like. Just don't get too clingy." << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
} // end greetUser


/****************************************************************/
/* Function:   displayOptions
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function displays the main menu options
/****************************************************************/
void displayOptions()
{
	displayHeader();
	std::cout << "Main Menu" << std::endl;
	std::cout << std::endl;
	std::cout << "P\tPrefix expression evaluation" << std::endl;
	std::cout << "Q\tQuit" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

} // end displayMainMenu


/****************************************************************/
/* Function:   displayHeader
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function displays the calculator header
/****************************************************************/
void displayHeader()
{
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "EVERYTHING CALCULATOR" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;

} // end of displayHeader


/****************************************************************/
/* Function:   getCharData
/* Inputs:     std::string prompt
/* Outputs:    char value
/* Purpose:    This function will get a char value from the user
/****************************************************************/
char getCharData(std::string prompt)
{
	char value;

	std::cout << prompt;
	std::cin >> value;

	clearCin();

	value = toupper(value);

	return value;

} // end getCharData


// This function will return a string data entered by users
std::string getStringData(std::string prompt)
{
	std::string value;

	std::cout << prompt;	

	std::getline(std::cin, value); // accepts spaces in the entry

	return value;

} // end of getStringData


/****************************************************************/
/* Function:   clearCin
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This functions clears the cin and then clears up to 120
/*				characters or hits enter.
/****************************************************************/
void clearCin()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

} // end clearCin