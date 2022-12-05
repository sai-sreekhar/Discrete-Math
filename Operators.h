#ifndef OPERATORS_H
#define OPERATORS_H

namespace operators
{
    const char NEGATION_OPERATOR{'~'};
    const char AND_OPERATOR{'^'};
    const char OR_OPERATOR{'V'};
    const char IMPLIES_OPERATOR{'>'};
}

bool isOperand(char input);
bool isOperator(char input);
int getOperatorPriority(char operatorInput);

#endif
