#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

class BinaryTree
{
    std::string inorderTraversal;

public:
    char data;
    BinaryTree *leftChild;
    BinaryTree *rightChild;

    explicit BinaryTree(char data);
    ~BinaryTree();
    void insertLeftChild(BinaryTree *leftChild);
    void insertRightChild(BinaryTree *rightChild);
    std::string getInorderTraversal();
};

#endif
