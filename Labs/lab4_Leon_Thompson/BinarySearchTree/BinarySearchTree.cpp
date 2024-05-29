//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file BinarySearchTree.cpp */
#include <iostream>
#include <iomanip>

#include "BinarySearchTree.h" 
#include "BinaryNode.h" 

//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////

/****************************************************************
* Function:   placeNode
* Inputs:     std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
*             std::shared_ptr<BinaryNode<ItemType>> newNodePtr
* Outputs:    std::shared_ptr<BinaryNode<ItemType>>
* Purpose:    Recursively finds where the given node should be placed and
              inserts it in a leaf at that point.
****************************************************************/
template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    // Base case: If the subtree is empty, return the new node
    if (subTreePtr == nullptr)
        return newNodePtr;
    else
    {
        // If the new node's item is less than the current node's item,
        // insert it into the left subtree
        if (subTreePtr->getItem() > newNodePtr->getItem())
            subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
        else 
            // Otherwise, insert it into the right subtree
            subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
        
        // Return the subtree pointer (unchanged or updated)
        return subTreePtr;
    }  // end if
}  // end placeNode


/****************************************************************
* Function:   removeValue
* Inputs:     std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
*             const ItemType target,
*             bool& success
* Outputs:    std::shared_ptr<BinaryNode<ItemType>>
* Purpose:    This function searches for the node containing the
*             target value in the binary search tree, removes it,
*             and maintains the binary search tree
****************************************************************/
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                                              const ItemType target, 
                                                                              bool& success)
{
    // Base case: If the subtree is empty, the target is not found
    if (subTreePtr == nullptr)           
    {
        success = false;
        return subTreePtr;
    }
    // If the target is found at the current node
    if (subTreePtr->getItem() == target)
    {
        subTreePtr = removeNode(subTreePtr);  // Remove the node
        success = true;
        return subTreePtr;
    }
    else 
    {
        // If the target is less than the current node's item, search in the left subtree
        if (subTreePtr->getItem() > target)
        {
            subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
        }
        else
        {
            // If the target is greater than the current node's item, search in the right subtree
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
        }
        return subTreePtr;
    }  // end if
}  // end removeValue


/****************************************************************
* Function:   removeNode
* Inputs:     std::shared_ptr<BinaryNode<ItemType>> nodePtr
* Outputs:    std::shared_ptr<BinaryNode<ItemType>>
* Purpose:    This function removes a node from the binary search tree
*             and adjusts the tree to maintain BST properties.
*             It handles three cases: leaf node, node with one child,
*             and node with two children.
****************************************************************/
template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
    // Case 1: Node is a leaf - it is deleted
    if (nodePtr->isLeaf())
    {
        nodePtr.reset();
        return nodePtr; // delete and return nullptr
    }
    // Case 2: Node has one child - parent adopts the right child
    else if (nodePtr->getLeftChildPtr() == nullptr)
    {
        return nodePtr->getRightChildPtr();
    }
    // Case 2: Node has one child - parent adopts the left child
    else if (nodePtr->getRightChildPtr() == nullptr)
    {
        return nodePtr->getLeftChildPtr();
    }
    // Case 3: Node has two children
    else
    {
        // Traditional way to remove a node with two children
        ItemType newNodeValue;
        // Remove the leftmost node from the right subtree and get its value
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
        // Replace the current node's item with the successor value
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }  // end if
}  // end removeNode


/****************************************************************
* Function:   removeLeftmostNode
* Inputs:     std::shared_ptr<BinaryNode<ItemType>> nodePtr,
*             ItemType& inorderSuccessor
* Outputs:    std::shared_ptr<BinaryNode<ItemType>>
* Purpose:    This function finds and removes the leftmost node
*             in a subtree, returning its value (inorder successor)
*             and maintaining the BST properties.
****************************************************************/
template<class ItemType> 
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr,
                                                    ItemType& inorderSuccessor)
{
    // Base case: If the left child is null, the current node is the leftmost node
    if (nodePtr->getLeftChildPtr() == nullptr)
    {
        inorderSuccessor = nodePtr->getItem();  // Record the inorder successor value
        return removeNode(nodePtr);  // Remove the leftmost node
    }
    else 
    {
        // Recursive step: Continue searching in the left subtree
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
        return nodePtr;  // Return the updated subtree pointer
    }  // end if      
}  // end removeLeftmostNode



/****************************************************************
* Function:   findNode
* Inputs:     std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
*             const ItemType& target
* Outputs:    std::shared_ptr<BinaryNode<ItemType>>
* Purpose:    This function searches for a node containing the
*             target value in the binary search tree using binary
*             search logic, and returns a pointer to the node if found.
****************************************************************/
template<class ItemType>
auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                          const ItemType& target) const 
{
    // Base case: If the subtree is empty, the target is not found
    if (subTreePtr == nullptr)
        return subTreePtr;  // Not found

    // If the target is found at the current node
    else if (subTreePtr->getItem() == target)
        return subTreePtr;  // Found

    // If the target is less than the current node's item, search in the left subtree
    else if (subTreePtr->getItem() > target)
        return findNode(subTreePtr->getLeftChildPtr(), target);

    // If the target is greater than the current node's item, search in the right subtree
    else
        return findNode(subTreePtr->getRightChildPtr(), target);
}  // end findNode



//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{   }  // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{  }  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
   rootPtr = this->copyTree(treePtr.rootPtr); // Call inherited method
}  // end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

/****************************************************************
* Function:   isEmpty
* Inputs:     None
* Outputs:    bool
* Purpose:    This function checks if the binary search tree is empty.
****************************************************************/
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return rootPtr == nullptr;  // Tree is empty if rootPtr is nullptr
}  // end isEmpty


/****************************************************************
* Function:   getHeight
* Inputs:     None
* Outputs:    int
* Purpose:    This function returns the height of the binary search tree.
****************************************************************/
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return this->getHeightHelper(rootPtr);  // Call inherited method to get height
}  // end getHeight


/****************************************************************
* Function:   getNumberOfNodes
* Inputs:     None
* Outputs:    int
* Purpose:    This function returns the number of nodes in the binary search tree.
****************************************************************/
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
    return this->getNumberOfNodesHelper(rootPtr);  // Call inherited method to get node count
}  // end getNumberOfNodes


/****************************************************************
* Function:   clear
* Inputs:     None
* Outputs:    None
* Purpose:    This function removes all nodes from the binary search tree.
****************************************************************/
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
    this->destroyTree(rootPtr);  // Call inherited method to destroy the tree
    rootPtr.reset();  // Reset root pointer to nullptr
}  // end clear


/****************************************************************
* Function:   getRootData
* Inputs:     None
* Outputs:    ItemType
* Purpose:    This function returns the data stored in the root of the tree.
*             Throws an exception if the tree is empty.
****************************************************************/
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcep)
{
    if (isEmpty())
        throw PrecondViolatedExcep("getRootData() called with empty tree.");
    
    return rootPtr->getItem();  // Return the data of the root node
}  // end getRootData


/****************************************************************
* Function:   setRootData
* Inputs:     const ItemType& newItem
* Outputs:    None
* Purpose:    This function is overridden to disable changing the root
*             value in a binary search tree, as it would violate BST properties.
****************************************************************/
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newItem) const throw(PrecondViolatedExcep)
{
    throw PrecondViolatedExcep("Cannot change root value in a BST!");
}  // end setRootData


/****************************************************************
* Function:   add
* Inputs:     const ItemType& newData
* Outputs:    bool
* Purpose:    This function adds a new node with the specified data to
*             the binary search tree, maintaining BST properties.
****************************************************************/
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    
    return true;  // Node added successfully
}  // end add


/****************************************************************
* Function:   remove
* Inputs:     const ItemType& target
* Outputs:    bool
* Purpose:    This function removes the node containing the target value
*             from the binary search tree, maintaining BST properties.
****************************************************************/
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);  // Attempt to remove the node
    return isSuccessful;  // Return whether removal was successful
}  // end remove


/****************************************************************
* Function:   getEntry
* Inputs:     const ItemType& anEntry
* Outputs:    ItemType
* Purpose:    This function searches for an entry in the binary search
*             tree and returns it if found. Throws an exception if the
*             entry is not found.
****************************************************************/
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException)
{
    std::shared_ptr<BinaryNode<ItemType>> nodeWithEntry = findNode(rootPtr, anEntry);
    
    // Check if the node with the entry was found
    if (nodeWithEntry == nullptr)
        throw NotFoundException("Entry not found in tree.");
    else
        return nodeWithEntry->getItem();  // Return the found entry
}  // end getEntry


/****************************************************************
* Function:   contains
* Inputs:     const ItemType& anEntry
* Outputs:    bool
* Purpose:    This function checks if the binary search tree contains
*             a node with the specified entry.
****************************************************************/
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
    // Check if findNode returns a nullptr
    return (findNode(rootPtr, anEntry) != nullptr);
}  // end contains


//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

/****************************************************************
* Function:   preorderTraverse
* Inputs:     void visit(ItemType&)
* Outputs:    None
* Purpose:    This function traverses the binary search tree in
*             preorder and applies the visit function to each node's data.
****************************************************************/
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
    this->preorder(visit, rootPtr);  // Call inherited method for preorder traversal
}  // end preorderTraverse


/****************************************************************
* Function:   inorderTraverse
* Inputs:     void visit(ItemType&)
* Outputs:    None
* Purpose:    This function traverses the binary search tree in
*             inorder and applies the visit function to each node's data.
****************************************************************/
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
    this->inorder(visit, rootPtr);  // Call inherited method for inorder traversal
}  // end inorderTraverse


/****************************************************************
* Function:   postorderTraverse
* Inputs:     void visit(ItemType&)
* Outputs:    None
* Purpose:    This function traverses the binary search tree in
*             postorder and applies the visit function to each node's data.
****************************************************************/
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
    this->postorder(visit, rootPtr);  // Call inherited method for postorder traversal
}  // end postorderTraverse



//////////////////////////////////////////////////////////////
//      Overloaded Operator 
//////////////////////////////////////////////////////////////

/****************************************************************
* Function:   operator=
* Inputs:     const BinarySearchTree<ItemType>& rightHandSide
* Outputs:    BinarySearchTree<ItemType>&
* Purpose:    This function assigns one binary search tree to another,
*             ensuring a deep copy of the tree structure.
****************************************************************/
template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::
                            operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
    if (!isEmpty())
        clear();  // Clear the current tree if it is not empty

    this = copyTree(&rightHandSide);  // Call inherited method to copy the tree

    return *this;  // Return reference to the current object
}  // end operator=


/****************************************************************
* Function:   displayTreeHelper
* Inputs:     std::shared_ptr<BinaryNode<ItemType>> treePtr,
*             int depth,
*             bool isLeft
* Outputs:    None
* Purpose:    This function prints the tree structure recursively,
*             displaying the nodes with appropriate indentation and
*             labels to show their hierarchical relationships.
****************************************************************/
template<class ItemType>
void BinarySearchTree<ItemType>::displayTreeHelper(std::shared_ptr<BinaryNode<ItemType>> treePtr, int depth, bool isLeft) const
{
    // Base case: If the current node is null, return
    if (treePtr == nullptr) {
        return;
    }

    // Recursive step: Print the right subtree first (to visualize it on the left)
    if (treePtr->getRightChildPtr() != nullptr) {
        displayTreeHelper(treePtr->getRightChildPtr(), depth + 1, false);
    }

    // Print the current node with appropriate indentation and label
    if (depth > 0) {
        // Indent the output according to the depth of the node
        std::cout << std::setw(depth * 4)
                  // Label the node as left or right child
                  << (isLeft ? "L-- " : "R-- ");
    }
    // Print the node's data (ID and Name)
    std::cout << treePtr->getItem().getID() << ": " << treePtr->getItem().getName() << std::endl;

    // Recursive step: Print the left subtree (to visualize it on the right)
    if (treePtr->getLeftChildPtr() != nullptr) {
        displayTreeHelper(treePtr->getLeftChildPtr(), depth + 1, true);
    }
}  // end displayTreeHelper


/****************************************************************
* Function:   displayTree
* Inputs:     None
* Outputs:    None
* Purpose:    This function prints the entire binary search tree
*             structure starting from the root.
****************************************************************/
template<class ItemType>
void BinarySearchTree<ItemType>::displayTree() const 
{
    // Start printing from the root of the tree at depth 0
    displayTreeHelper(rootPtr, 0, false);
}  // end displayTree




