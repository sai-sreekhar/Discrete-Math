#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

class BinaryTree
{
    std::string inorderTraversal;

public:
    char data; //The value of the node
    BinaryTree *leftChild; //Pointer to left child
    BinaryTree *rightChild; //Pointer to right child

    explicit BinaryTree(char data); //Constructor for the node
    ~BinaryTree(); //Destructor for the node
    void insertLeftChild(BinaryTree *leftChild); //Inserts left child
    void insertRightChild(BinaryTree *rightChild); //Inserts right child
    std::string getInorderTraversal(); //Returns the inorder traversal
};

#endif
