#include "Operators.h"

bool isOperand(char input)
{
    if (input >= 'a' && input <= 'z')
    {
        return true;
    }

    return false;
}

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
