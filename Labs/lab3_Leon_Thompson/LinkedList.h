#ifndef LINKEDLIST_
#define LINKEDLIST_

#include "Node.h"
#include <vector>

class LinkedList 
{
    private:
        Node* headPtr;    // Pointer to the first node in the linked list
        int numItems;     // Number of items in the list

    public:
        // Default Constructor
        LinkedList();
        
        // Copy constructor
        LinkedList(const LinkedList& other);
        
        // Destructor - frees dynamically allocated memory
        ~LinkedList();
        
        // Accessor for number of items in LinkedList
        int getNumItems() const;

        // This function creates a new node given the category
        // and line, groups it with like categories and orders 
        // lines alphabetically within its category.
        void add(const std::string& category, const std::string& line);

        // Method to convert list contents to a vector
        std::vector<std::string> toVector() const;
}; // end LinkedList

#include "LinkedList.cpp"

#endif // LINKEDLIST_H
