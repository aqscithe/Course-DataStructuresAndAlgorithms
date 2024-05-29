/*
-------------------------------------------------------------------------
Name:			Leon Thompson
Date:			04/21/2024
Lab #:			3
Status: 		Completed
-------------------------------------------------------------------------
Description
	This program processes text files from a user with categories and 
    corresponding lines. Categories are grouped together in order of 
    appearance, but their lines are sorted alphabetically. This info
    is placed in a linked list and displayed to the user.
-------------------------------------------------------------------------
*/

#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>


void greetUser();
std::string getStringData(std::string);
void displayListContents(const std::vector<std::string>&);



int main()
{

    greetUser();

    // Get filename from user
    std::string file = getStringData("Please enter the file to be processed: ");

    // Ensure file opens successfully
    std::ifstream fileStream(file);
    if (!fileStream) 
    {
        std::cerr << "Error: The file \"" << file << "\" could not be opened.\nPlease check to ensure it exists" << std::endl;
        return 1; 
    } // end if


    // LinkedList to store category and line data from file
    LinkedList list;
    std::string category;
    std::string line;

    // Read all the lines in the file
    while (std::getline(fileStream, category) && std::getline(fileStream, line)) 
    {
        // Add node with category and line data to LinkedList
        list.add(category, line);
    } // end while

    // Close file stream
    fileStream.close(); 

    // Convert LinkedList to a vector
    std::vector<std::string> listContents = list.toVector();

    displayListContents(listContents);
    

} // end main



/****************************************************************/
/* Function:   greetUser
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function greets the user upon app load
/****************************************************************/
void greetUser()
{
	std::cout << "WELCOME TO THE CATEGORY PROCESSOR" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << "Here is how it works:" << std::endl;
	std::cout << "\tJust type in the name of the file you want me to process. Ex: specialSauce.txt" << std::endl;
	std::cout << "\tPress enter" << std::endl;
	std::cout << "\tAnd this bad boy will get those categories grouped and lines sorted alphabetically in no time flat." << std::endl;
	std::cout << "\tIt will even display the results once processing is completed." << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
} // end greetUser


/****************************************************************/
/* Function:   getStringData
/* Inputs:     std::string prompt
/* Outputs:    std::string value
/* Purpose:    This function will return a string data entered by users
/****************************************************************/
std::string getStringData(std::string prompt)
{
	std::string value;

	std::cout << prompt;	

	std::getline(std::cin, value); // accepts spaces in the entry

	return value;

} // end getStringData


/****************************************************************/
/* Function:   displayListContents
/* Inputs:     const std::vector<std::string>& listContents
/* Outputs:    none
/* Purpose:    This function takes the contents of a list containing
               categories and lines and displays them in an 
               organized format. Each category is printed first
               with its corresponding lines below it with a tab
               as the first character.
/****************************************************************/
void displayListContents(const std::vector<std::string>& listContents)
{
    // Traverse string entries in vector
    std::string currentCategory;
    for (const auto& entry : listContents) 
    {
        // Identify category and line in entry
        size_t colonPos = entry.find(':');
        std::string entryCategory = entry.substr(0, colonPos);
        std::string entryLine = entry.substr(colonPos + 2);

        // if entry not same as current category, output new
        // category and update current category
        if (entryCategory != currentCategory) 
        {
            std::cout << entryCategory << std::endl;
            currentCategory = entryCategory;
        } // end if
        // Entry lines start with a tab
        std::cout << "\t" << entryLine << std::endl;
    } // end for
}// end displayListContents