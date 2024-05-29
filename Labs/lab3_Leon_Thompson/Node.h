
#ifndef NODE_
#define NODE_

#include <string>

class Node
{
    private:
        std::string category;
        std::string line;
        Node*       next;

    public:
        // Default Constructor
        Node();

        // Copy Constructor
        Node(const std::string& aCategory, const std::string& aLine);

        // Copy Constructor
        Node(const std::string& aCategory, const std::string& aLine, Node* nextNodePtr);

        // Destructor - next is set to nullptr
        ~Node();

        // Setter method for category
        void setCategory(const std::string& aCategory);

        // Setter method for line
        void setLine(const std::string& aLine);

        // Setter method for next pointer
        void setNext(Node* nextNodePtr);

        // Getter method for category
        std::string getCategory() const;

        // Getter method for line
        std::string getLine() const;

        // Getter method for next pointer
        Node*       getNext() const;

};

#include "Node.cpp"

#endif