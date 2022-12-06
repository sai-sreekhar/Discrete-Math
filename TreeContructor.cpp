#include <iostream>
#include <stack>
#include "Operators.h"
#include "TreeConstructor.h"

using namespace std;

string infixToPostfix(string infixExpression)
{
    stack<char> operatorStack;
    string postfixExpression;
    for (char data : infixExpression)
    {
        if (isOperand(data))
        {
            postfixExpression.push_back(data);
        }
        else if (isOperator(data))
        {
            while (!operatorStack.empty() && // while operator stack is not empty
                   getOperatorPriority(operatorStack.top()) > getOperatorPriority(data) && // while top of stack has higher priority than current operator
                   operatorStack.top() != '(') // while top of stack is not a left parenthesis
            {
                postfixExpression.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(data);
        }
        else if (data == '(')
        {
            operatorStack.push(data);
        }
        else if (data == ')')
        {
            while (operatorStack.top() != '(') // while top of stack is not a left parenthesis
            {
                postfixExpression.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.pop();
        }
    }
    while (!operatorStack.empty())
    {
        postfixExpression.push_back(operatorStack.top());
        operatorStack.pop();
    }
    return postfixExpression;
}

// Convert a postfix expression to a binary tree.
BinaryTree *postfixExpressionToTree(string *postfixExpression)
{
    // Check if the expression is empty.
    if (postfixExpression->empty())
    {
        std::cout << "Expression is Empty";
        exit(1);
    }

    // Get the last character of the expression.
    char lastCharacter = postfixExpression->back();

    // Remove the last character from the expression.
    postfixExpression->resize(postfixExpression->length() - 1);

    // Check if the last character is an operand.
    if (isOperand(lastCharacter))
        return new BinaryTree(lastCharacter); // Return a new binary tree if it is an operand.
    else
    {
        auto current = new BinaryTree(lastCharacter); // Create a new binary tree if it is an operator.
        BinaryTree *rightChild = postfixExpressionToTree(postfixExpression); // Create the right child of the tree.
        current->insertRightChild(rightChild); // Insert the right child into the tree.
        if (lastCharacter != operators::NEGATION_OPERATOR)
        {
            BinaryTree *leftChild = postfixExpressionToTree(postfixExpression); // Create the left child of the tree.
            current->insertLeftChild(leftChild); // Insert the left child into the tree.
        }
        return current; // Return the current tree.
    }
}

// Convert binary tree to infix expression
string getInfixExpression(BinaryTree *root)
{
    // Return the data in the root node if it is a leaf node
    if (!root->leftChild and !root->rightChild)
    {
        return string(&(root->data));
    }
    string infixExpression;
    // Add a left parenthesis to the infix expression
    // only if the root node is not a negation operator
    if (root->data != operators::NEGATION_OPERATOR)
    {
        infixExpression.push_back('(');
    }
    // Add the left child of the root node to the infix expression
    if (root->leftChild)
    {
        infixExpression.append(getInfixExpression(root->leftChild));
    }
    // Add the data in the root node to the infix expression
    infixExpression.push_back(root->data);
    // Add the right child of the root node to the infix expression
    if (root->rightChild)
    {
        infixExpression.append(getInfixExpression(root->rightChild));
    }
    // Add a right parenthesis to the infix expression
    // only if the root node is not a negation operator
    if (root->data != operators::NEGATION_OPERATOR)
    {
        infixExpression.push_back(')');
    }
    return infixExpression;
}
