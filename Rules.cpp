#include "Rules.h"

using namespace std;
using namespace operators;

bool isValid(Proof *lineInput)
{
    using namespace ruleLiterals;
    if (lineInput->ruleLiteral == PREMISE)
    {
        return isValidPremise(lineInput);
    }
    else if (lineInput->ruleLiteral == AND_INTRODUCIION)
    {
        return isValidAndIntroduction(lineInput);
    }
    else if (lineInput->ruleLiteral == AND_ELMINATION_1)
    {
        return isValidAndElimination1(lineInput);
    }
    else if (lineInput->ruleLiteral == AND_ELIMNATION_2)
    {
        return isValidAndElimnation2(lineInput);
    }
    else if (lineInput->ruleLiteral == OR_INTRODUCTION_1)
    {
        return isValidOrIntroduction1(lineInput);
    }
    else if (lineInput->ruleLiteral == OR_INTRODUCTION_2)
    {
        return isValidOrIntroduction2(lineInput);
    }
    else if (lineInput->ruleLiteral == IMPLIES_ELIMINATION)
    {
        return isValidImpliesElimination(lineInput);
    }
    else if (lineInput->ruleLiteral == MODUS_TOLLENS)
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
    return lineInput->formula->leftChild->getInorderTraversal() == lineInput->line1->formula->getInorderTraversal() and
           lineInput->formula->rightChild->getInorderTraversal() == lineInput->line2->formula->getInorderTraversal();
}

bool isValidAndElimination1(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula or lineInput->line1->formula->data != AND_OPERATOR)
        return false;
    return lineInput->line1->formula->leftChild->getInorderTraversal() == lineInput->formula->getInorderTraversal();
}

bool isValidAndElimnation2(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula or lineInput->line1->formula->data != AND_OPERATOR)
        return false;
    return lineInput->line1->formula->rightChild->getInorderTraversal() == lineInput->formula->getInorderTraversal();
}

bool isValidOrIntroduction1(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    return lineInput->line1->formula->getInorderTraversal() == lineInput->formula->leftChild->getInorderTraversal();
}

bool isValidOrIntroduction2(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    return lineInput->line1->formula->getInorderTraversal() == lineInput->formula->rightChild->getInorderTraversal();
}

bool isValidImpliesElimination(Proof *lineInput)
{
    if (!lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    if (!lineInput->line2 or !lineInput->line2->isValidFormula)
        return false;
    if (lineInput->line1->formula->data != IMPLIES_OPERATOR)
        return false;
    return lineInput->line1->formula->leftChild->getInorderTraversal() == lineInput->line2->formula->getInorderTraversal() and
           lineInput->line1->formula->rightChild->getInorderTraversal() == lineInput->formula->getInorderTraversal();
}

bool isValidModusTollens(Proof *lineInput)
{
    if (!lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    if (!lineInput->line2 or !lineInput->line2->isValidFormula)
        return false;
    if (lineInput->line1->formula->data != IMPLIES_OPERATOR)
        return false;
    if (lineInput->formula->data != NEGATION_OPERATOR or lineInput->line2->formula->data != NEGATION_OPERATOR)
        return false;
    return lineInput->line1->formula->leftChild->getInorderTraversal() == lineInput->formula->rightChild->getInorderTraversal() and
           lineInput->line1->formula->rightChild->getInorderTraversal() == lineInput->line2->formula->rightChild->getInorderTraversal();
}
