#include "Node.h"

/****************************************************************/
/* Function:   Node
/* Inputs:     none
/* Outputs:    none
/* Purpose:    Default constructor
/****************************************************************/
Node::Node() : category(""), line(""), next(nullptr)
{
} // end Node


/****************************************************************/
/* Function:   Node
/* Inputs:     const std::string& aCategory, const std::string& aLine
/* Outputs:    none
/* Purpose:    Copy Constructor - deep copy of node's data
               attributes. Next set to nullptr.
/****************************************************************/
Node::Node(const std::string &aCategory, const std::string &aLine) : category(aCategory), line(aLine), next(nullptr)
{
} // end Node

/****************************************************************/
/* Function:   Node
/* Inputs:     const std::string& aCategory, const std::string& aLine, Node* nextNodePtr
/* Outputs:    none
/* Purpose:    Copy Constructor - deep copy of LinkedList's data
               attributes and nodes.
/****************************************************************/
Node::Node(const std::string &aCategory, const std::string &aLine, Node *nextNodePtr) : category(aCategory), line(aLine), next(nextNodePtr)
{
} // end Node


/****************************************************************/
/* Function:   Node
/* Inputs:     none
/* Outputs:    none
/* Purpose:    Destructor - next is set to nullptr
/****************************************************************/
Node::~Node()
{
    if(next != nullptr)
    {
        next = nullptr;
    }
} // end ~Node


/****************************************************************/
/* Function:   Node
/* Inputs:     const std::string &aCategory
/* Outputs:    none
/* Purpose:    Setter method for category
/****************************************************************/
void Node::setCategory(const std::string &aCategory)
{
    category = aCategory;
} // end SetCategory

/****************************************************************/
/* Function:   Node
/* Inputs:     const std::string &aLine
/* Outputs:    none
/* Purpose:    Setter method for line
/****************************************************************/
void Node::setLine(const std::string &aLine)
{
    line = aLine;
} // end setLine

/****************************************************************/
/* Function:   Node
/* Inputs:     Node *nextNodePtr
/* Outputs:    none
/* Purpose:    Setter method for next pointer
/****************************************************************/
void Node::setNext(Node *nextNodePtr)
{
    next = nextNodePtr;
} // end setNext

/****************************************************************/
/* Function:   Node
/* Inputs:     none
/* Outputs:    std::string category
/* Purpose:    Getter method for category
/****************************************************************/
std::string Node::getCategory() const
{
    return category;
} // end getCategory

/****************************************************************/
/* Function:   Node
/* Inputs:     none
/* Outputs:    std::string line
/* Purpose:    Getter method for line
/****************************************************************/
std::string Node::getLine() const
{
    return line;
} // end getLine

/****************************************************************/
/* Function:   Node
/* Inputs:     none
/* Outputs:    none
/* Purpose:    Getter method for next pointer
/****************************************************************/
Node *Node::getNext() const
{
    return next;
} // end getNext
