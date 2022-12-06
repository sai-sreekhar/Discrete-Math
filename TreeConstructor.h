#ifndef TREECONSTRUCTOR_H
#define TREECONSTRUCTOR_H
#include "BinaryTree.h"

// Converts infix expression to postfix expression
std::string infixToPostfix(std::string infix_exp);

// Converts postfix expression to a binary tree
BinaryTree *postfixExpressionToTree(std::string *postfix);

// Converts binary tree to infix expression
std::string getInfixExpression(BinaryTree *root);

#endif
