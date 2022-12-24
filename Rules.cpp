#include "Rules.h"

using namespace std;
using namespace operators;

//isValid() checks to see if a line input is a valid line
//in a proof. It does this by checking the rule of the line
//input and then calling the appropriate function to check
//the validity of the line input.
//It returns true if the line input is valid and false otherwise.
//It uses the following functions:
//isValidPremise()
//isValidAndIntroduction()
//isValidAndElimination1()
//isValidAndElimination2()
//isValidOrIntroduction1()
//isValidOrIntroduction2()
//isValidImpliesElimination()
//isValidModusTollens()
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
        return isValidAndElimination2(lineInput);
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

/* isValidPremise
 * Checks if a line is a premise. A line is a premise if it has no
 * antecedents.
 * Parameters:
 *      lineInput: a pointer to the line to check
 * Returns:
 *      true if lineInput is a premise
 */
bool isValidPremise(Proof *lineInput)
{
    if(!lineInput->line1 &&  !lineInput->line2)
        return true;
    return false;
    // return !(lineInput->line1 or lineInput->line2);
}

// This function is used to check if a line of proof has a valid introduction of the and operator. 
// It checks if the line is valid, if the line is valid the function checks if the left child of the line is equal to the left child of the first line and if the right child of the line is equal to the right child of the second line.
// The function returns true if the line is valid and the left child of the line is equal to the left child of the first line and the right child of the line is equal to the right child of the second line.
// The function returns false otherwise.

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

// This function checks if the line is a valid elimination of 1 from a conjunction
// and returns false if the line is invalid or the line is not an elimination of 1 from a conjunction
// and returns true if the line is valid and an elimination of 1 from a conjunction
// This function takes in a Proof pointer and returns a boolean value

bool isValidAndElimination1(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula or lineInput->line1->parseTree->data != AND_OPERATOR)
        return false;
    return lineInput->line1->parseTree->leftChild->getInorderTraversal() == lineInput->parseTree->getInorderTraversal();
}

bool isValidAndElimination2(Proof *lineInput)
{
    //Checks if the lineInput is valid and is an AND_ELIMINATION2
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula or lineInput->line1->parseTree->data != AND_OPERATOR)
        return false;
    //Checks if the second child of the lineInput's first line is the same as the lineInput's parseTree
    return lineInput->line1->parseTree->rightChild->getInorderTraversal() == lineInput->parseTree->getInorderTraversal();
}

//This function checks if a proof is valid using the Or Introduction Rule. It takes in a proof and checks if the proof is valid, if it is valid, it returns true, otherwise it returns false. It also checks if the proof is valid by checking if the proof has a line1 and line2, as well as if line1 is a valid formula. Then it checks if line1 is equal to the left child of line 2. If it is, then the proof is valid, otherwise it is not.

bool isValidOrIntroduction1(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    return lineInput->line1->parseTree->getInorderTraversal() == lineInput->parseTree->leftChild->getInorderTraversal();
}

// This function checks if the formula on the right side of the line is the same as the formula on the line that the line claims to be a proof of.
// If so, the function returns true, else it returns false.
// The function takes in a Proof pointer, and checks if the parseTree of the line is the same as the parseTree of the line to the left of the line
// If so, the function returns true, else it returns false.
bool isValidOrIntroduction2(Proof *lineInput)
{
    if (lineInput->line2 or !lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    return lineInput->line1->parseTree->getInorderTraversal() == lineInput->parseTree->rightChild->getInorderTraversal();
}

// This function checks if the input line is a valid elimination of IMPLIES
// The input line should have 2 lines as input, and the first line should have a formula that is an IMPLIES operator
// The second line should have the left child of the first line, and the input line should have the right child of the first line
// If all of these conditions are met, then the input line is a valid elimination of IMPLIES
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

// This function checks to see if a proof is a valid modus tollens proof.
// A proof is valid if it has two lines, the first of which is an implication,
// the second of which is a negation, and the negation of the first line is the
// same as the second line.
bool isValidModusTollens(Proof *lineInput)
{
    // Check to see if the first line is valid.
    if (!lineInput->line1 or !lineInput->line1->isValidFormula)
        return false;
    // Check to see if the second line is valid.
    if (!lineInput->line2 or !lineInput->line2->isValidFormula)
        return false;
    // Check to see if the first line is an implication.
    if (lineInput->line1->parseTree->data != IMPLIES_OPERATOR)
        return false;
    // Check to see if the second line is a negation.
    if (lineInput->parseTree->data != NEGATION_OPERATOR or lineInput->line2->parseTree->data != NEGATION_OPERATOR)
        return false;
    // Check to see if the negation of the first line is the same as the second line.
    return lineInput->line1->parseTree->leftChild->getInorderTraversal() == lineInput->parseTree->rightChild->getInorderTraversal() and
           lineInput->line1->parseTree->rightChild->getInorderTraversal() == lineInput->line2->parseTree->rightChild->getInorderTraversal();
}
