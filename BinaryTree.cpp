#include "BinaryTree.h"

BinaryTree::BinaryTree(char data) : data(data), leftChild(nullptr), rightChild(nullptr) {}

// destructor for BinaryTree class
BinaryTree::~BinaryTree()
{
    // delete the left child
    delete leftChild;
    // delete the right child
    delete rightChild;
}

void BinaryTree::insertLeftChild(BinaryTree *leftChild)
{
    // Set the left child of this node to the left child passed in.
    this->leftChild = leftChild;
}

void BinaryTree::insertRightChild(BinaryTree *rightChild)
{
    // Assign the rightChild BinaryTree pointer to the input
    // BinaryTree pointer
    this->rightChild = rightChild;
}

std::string BinaryTree::getInorderTraversal()
{
    // If the inorder traversal has already been calculated, return it
    if (!inorderTraversal.empty())
    {
        return inorderTraversal;
    }

    // If the left child exists, recurse and add the result to the traversal
    if (leftChild)
    {
        inorderTraversal += leftChild->getInorderTraversal();
    }

    // Add the data to the traversal
    inorderTraversal += data;

    // If the right child exists, recurse and add the result to the traversal
    if (rightChild)
    {
        inorderTraversal += rightChild->getInorderTraversal();
    }

    return inorderTraversal;
}
