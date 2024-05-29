#include "LinkedList.h"
#include <iostream>


/****************************************************************/
/* Function:   LinkedList
/* Inputs:     none
/* Outputs:    none
/* Purpose:    Default constructor
/****************************************************************/
LinkedList::LinkedList() : headPtr(nullptr), numItems(0) 
{
}


/****************************************************************/
/* Function:   LinkedList
/* Inputs:     const LinkedList& other
/* Outputs:    none
/* Purpose:    Copy Constructor - deep copy of LinkedList's data
               attributes and nodes.
/****************************************************************/
LinkedList::LinkedList(const LinkedList& other) : headPtr(nullptr), numItems(other.numItems) 
{
    // Points to last node in the new list
    Node* last = nullptr;  

    // Start from the head of the other list
    Node* currentNodeOther = other.headPtr;  

    // Traverse other list
    while (currentNodeOther != nullptr) 
    {
        // Copy node data to dynamically allocated memory for new node
        Node* newNode = new Node(currentNodeOther->getCategory(), currentNodeOther->getLine()); 
        if (last == nullptr) 
        {
            // If this is the first node, set it as the head of the list
            headPtr = newNode;  
        } else 
        {
            // Set the new node as the next of the last node
            last->setNext(newNode);  
        } // end if

        // Update last to the newly created node
        last = newNode;  

        // Move to the next node in the other list
        currentNodeOther = currentNodeOther->getNext();  
    } // end while
}


/****************************************************************/
/* Function:   ~LinkedList
/* Inputs:     none
/* Outputs:    none
/* Purpose:    Destructor - frees dynamically allocated memory
/****************************************************************/
LinkedList::~LinkedList() 
{
    // Start at head node
    Node* currentNode = headPtr;

    // Traverse nodes in list
    while (currentNode != nullptr) 
    {
        // Free memory from dynamically allocated node
        Node* nextNode = currentNode->getNext();
        delete currentNode;

        // Move on tonext node
        currentNode = nextNode;
    } // end while
}


/****************************************************************/
/* Function:   add
/* Inputs:     const std::string& category, const std::string& line
/* Outputs:    none
/* Purpose:    This function creates a new node given the category
/*             and line, groups it with like categories and orders 
/*             lines alphabetically within its category.
/****************************************************************/
void LinkedList::add(const std::string& category, const std::string& line) 
{
    // Create new node
    Node* newNode = new Node(category, line);

    // Check if list is empty
    if (!headPtr) 
    { 
        headPtr = newNode;
    } else 
    {
        Node* current = headPtr;
        Node* prev = nullptr;
        Node* lastInCategory = nullptr;

        // Traverse linkedlist until the end is reached looking for category
        while (current != nullptr && current->getCategory() != category) 
        {
            prev = current;
            current = current->getNext();
        } // end while

        // If current is NULL, this must be the first occurrence of a category
        if (current == nullptr) 
        { 
            // New node placed at end of list
            prev->setNext(newNode);
        } else 
        { 
            // Existing category found
            // Find the end of this category
            while (current != nullptr && current->getCategory() == category) 
            {
                // Check for correct insertion point for the line
                if (current->getLine() > line)
                {
                    break;
                }  // end if

                lastInCategory = current;
                current = current->getNext();
            } // end while

            // Insert the new node in the correct position within the category
            newNode->setNext(current);

            if (lastInCategory) 
            {
                lastInCategory->setNext(newNode);
            } else 
            {   // The new node is the first in this category
                // If there is a node before
                if (prev) 
                {
                    // Place the new node after that node
                    newNode->setNext(prev->getNext());
                    prev->setNext(newNode);
                } else 
                {
                    // Otherwise, set new node as head
                    newNode->setNext(headPtr);
                    headPtr = newNode;
                } // end if
            } // end if
        } // end if
    }
    numItems++;
} // end add


/****************************************************************/
/* Function:   toVector
/* Inputs:     none
/* Outputs:    std::vector<std::string> result
/* Purpose:    Converts LinkedList to a std::vector
/****************************************************************/
std::vector<std::string> LinkedList::toVector() const 
{
    // Initialize string vector
    std::vector<std::string> result;

    // Traverse LinkedList
    Node* current = headPtr;
    while (current != nullptr) 
    {
        // Place category at end of vector, separated by a colon and space
        result.push_back(current->getCategory() + ": " + current->getLine());
        current = current->getNext();
    } // end while
    return result;

} // end toVector


/****************************************************************/
/* Function:   getNumItems
/* Inputs:     none
/* Outputs:    int numItems
/* Purpose:    Accessor for number of items in LinkedList
/****************************************************************/
int LinkedList::getNumItems() const 
{
    return numItems;
}
