#include "Operators.h"

bool isOperand(char input)
{
    // Check if the input is a lowercase letter
    return input >= 'a' && input <= 'z';
}

// This function takes a character as input and compares it with the operators
// defined in the operators namespace. If the input matches one of the operators
// in the namespace, then it returns true. Otherwise, it returns false.
bool isOperator(char input)
{
    using namespace operators;
    const char validOperators[] = {NEGATION_OPERATOR, AND_OPERATOR, OR_OPERATOR, IMPLIES_OPERATOR};
    for (int i = 0; i < 4; i++)
    {
        if (input == validOperators[i])
        {
            return true;
        }
    }
    return false;
}

int getOperatorPriority(char operatorInput)
{
    // Returns the priority of the operators.
    // The higher the value, the higher the priority.
    using namespace operators;
    switch (operatorInput)
    {
    case NEGATION_OPERATOR:
    {
        return 4;
    }
    case AND_OPERATOR:
    case OR_OPERATOR:
        return 3;
    case IMPLIES_OPERATOR:
    {
        return 2;
    }
    default:
    {
        return -1;
    }
    }
}
