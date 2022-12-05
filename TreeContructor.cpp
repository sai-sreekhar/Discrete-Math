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
            while (!operatorStack.empty() &&
                   getOperatorPriority(operatorStack.top()) > getOperatorPriority(data) &&
                   operatorStack.top() != '(')
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
            while (operatorStack.top() != '(')
            {
                postfixExpression.push_back(operatorStack.top()); // keep popping operators till next open parenthesis
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

BinaryTree *postfixExpressionToTree(string *postfixExpression)
{
    if (postfixExpression->empty())
    {
        std::cout << "Expression is Empty";
        exit(1);
    }

    char lastCharacter = postfixExpression->back();

    postfixExpression->resize(postfixExpression->length() - 1);

    if (isOperand(lastCharacter))
        return new BinaryTree(lastCharacter);
    else
    {
        auto current = new BinaryTree(lastCharacter);
        BinaryTree *rightChild = postfixExpressionToTree(postfixExpression);
        current->insertRightChild(rightChild);
        if (lastCharacter != operators::NEGATION_OPERATOR)
        {
            BinaryTree *leftChild = postfixExpressionToTree(postfixExpression);
            current->insertLeftChild(leftChild);
        }
        return current;
    }
}

string getInfixExpression(BinaryTree *root)
{
    if (!root->leftChild and !root->rightChild)
    {
        return string(&(root->data));
    }
    string infixExpression;
    if (root->data != operators::NEGATION_OPERATOR)
    {
        infixExpression.push_back('(');
    }
    if (root->leftChild)
    {
        infixExpression.append(getInfixExpression(root->leftChild));
    }
    infixExpression.push_back(root->data);
    if (root->rightChild)
    {
        infixExpression.append(getInfixExpression(root->rightChild));
    }
    if (root->data != operators::NEGATION_OPERATOR)
    {
        infixExpression.push_back(')');
    }
    return infixExpression;
}
