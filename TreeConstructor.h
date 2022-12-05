#ifndef TREECONSTRUCTOR_H
#define TREECONSTRUCTOR_H
#include "BinaryTree.h"

std::string infixToPostfix(std::string infix_exp);

BinaryTree *postfixExpressionToTree(std::string *postfix);

std::string getInfixExpression(BinaryTree *root);

#endif
