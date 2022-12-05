#include "BinaryTree.h"

BinaryTree::BinaryTree(char data)
{
    data = data;
    leftChild = nullptr;
    rightChild = nullptr;
}

BinaryTree::~BinaryTree()
{
    delete leftChild;
    delete rightChild;
}

void BinaryTree::insertLeftChild(BinaryTree *leftChild)
{
    this->leftChild = leftChild;
}

void BinaryTree::insertRightChild(BinaryTree *rightChild)
{
    this->rightChild = rightChild;
}

std::string BinaryTree::getInorderTraversal()
{
    if (!inorderTraversal.empty())
    {
        return inorderTraversal;
    }

    if (leftChild)
    {
        inorderTraversal += leftChild->getInorderTraversal();
    }

    inorderTraversal += data;
    
    if (rightChild)
    {
        inorderTraversal += rightChild->getInorderTraversal();
    }
    
    return inorderTraversal;
}
