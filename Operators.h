#ifndef OPERATORS_H
#define OPERATORS_H

namespace operators
{
    // The negation operator. It is defined as a single character: ~
    const char NEGATION_OPERATOR{'~'};
    // The AND operator. It is defined as a single character: ^
    const char AND_OPERATOR{'^'};
    // The OR operator. It is defined as a single character: V
    const char OR_OPERATOR{'V'};
    // The IMPLIES operator. It is defined as a single character: >
    const char IMPLIES_OPERATOR{'>'};
}

// Checks if the input is an operand
bool isOperand(char input);

// Checks if the input is an operator
bool isOperator(char input);

// Gets the priority of an operator
int getOperatorPriority(char operatorInput);

#endif
