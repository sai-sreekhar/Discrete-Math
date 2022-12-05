#include "Rules.h"

using namespace std;
using namespace operators;

bool isValid(Proof *lineInput)
{
    using namespace ruleLiterals;
    if (lineInput->rule == PREMISE)
    {
        return isValidPremise(lineInput);
    }
    else if (lineInput->rule == AND_INTRODUCIION)
    {
        return isValidAndIntroduction(lineInput);
    }
    else if (lineInput->rule == AND_ELMINATION_1)
    {
        return isValidAndElimination1(lineInput);
    }
    else if (lineInput->rule == AND_ELIMNATION_2)
    {
        return isValidAndElimnation2(lineInput);
    }
    else if (lineInput->rule == OR_INTRODUCTION_1)
    {
        return isValidOrIntroduction1(lineInput);
    }
    else if (lineInput->rule == OR_INTRODUCTION_2)
    {
        return isValidOrIntroduction2(lineInput);
    }
    else if (lineInput->rule == IMPLIES_ELIMINATION)
    {
        return isValidImpliesElimination(lineInput);
    }
    else if (lineInput->rule == MODUS_TOLLENS)
    {
        return isValidModusTollens(lineInput);
    }
    else
        return false;
}

bool isValidPremise(Proof *lineInput)
{
    return !(lineInput->line1 or lineInput->line2);
}

bool isValidAndIntroduction(Proof *lineInput)
{
    if (!lineInput->line1 or !lineInput->line1->isValidFormula)
    {
        return false;
    }
    if (!lineInput->line2 or !lineInput->line2->isValidFormula)
    {
        return false;
    }
    return lineInput->parseTree->leftChild->getInorderTraversal() == lineInput->line1->parseTree->getInorderTraversal() and
           lineInput->parseTree->rightChild->getInorderTraversal() == lineInput->line2->parseTree->getInorderTraversal();
}

bool isValidAndElimination1(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula or lineInput->line1->parseTree->data != AND_OPERATOR)
        return false;
    return lineInput->line1->parseTree->leftChild->getInorderTraversal() == lineInput->parseTree->getInorderTraversal();
}

bool isValidAndElimnation2(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula or lineInput->line1->parseTree->data != AND_OPERATOR)
        return false;
    return lineInput->line1->parseTree->rightChild->getInorderTraversal() == lineInput->parseTree->getInorderTraversal();
}

bool isValidOrIntroduction1(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    return lineInput->line1->parseTree->getInorderTraversal() == lineInput->parseTree->leftChild->getInorderTraversal();
}

bool isValidOrIntroduction2(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    return lineInput->line1->parseTree->getInorderTraversal() == lineInput->parseTree->rightChild->getInorderTraversal();
}

bool isValidImpliesElimination(Proof *lineInput)
{
    if (!lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    if (!lineInput->line2 or !lineInput->line2->isValidFormula)
        return false;
    if (lineInput->line1->parseTree->data != IMPLIES_OPERATOR)
        return false;
    return lineInput->line1->parseTree->leftChild->getInorderTraversal() == lineInput->line2->parseTree->getInorderTraversal() and
           lineInput->line1->parseTree->rightChild->getInorderTraversal() == lineInput->parseTree->getInorderTraversal();
}

bool isValidModusTollens(Proof *lineInput)
{
    if (!lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    if (!lineInput->line2 or !lineInput->line2->isValidFormula)
        return false;
    if (lineInput->line1->parseTree->data != IMPLIES_OPERATOR)
        return false;
    if (lineInput->parseTree->data != NEGATION_OPERATOR or lineInput->line2->parseTree->data != NEGATION_OPERATOR)
        return false;
    return lineInput->line1->parseTree->leftChild->getInorderTraversal() == lineInput->parseTree->rightChild->getInorderTraversal() and
           lineInput->line1->parseTree->rightChild->getInorderTraversal() == lineInput->line2->parseTree->rightChild->getInorderTraversal();
}
