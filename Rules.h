#ifndef RULES_H
#define RULES_H
#include <string>
#include "Operators.h"
#include "ValidateProof.h"

namespace verbs
{
    const char INTRODUCTION{'i'};
    const char ELIMINATION{'e'};
}

namespace ruleLiterals
{
    using namespace operators;
    const std::string PREMISE{"P"};
    const std::string AND_INTRODUCIION{AND_OPERATOR, verbs::INTRODUCTION};
    const std::string AND_ELMINATION_1{AND_OPERATOR, verbs::ELIMINATION, '1'};
    const std::string AND_ELIMNATION_2{AND_OPERATOR, verbs::ELIMINATION, '2'};
    const std::string OR_INTRODUCTION_1{OR_OPERATOR, verbs::INTRODUCTION, '1'};
    const std::string OR_INTRODUCTION_2{OR_OPERATOR, verbs::INTRODUCTION, '2'};
    const std::string IMPLIES_ELIMINATION{IMPLIES_OPERATOR, verbs::ELIMINATION};
    const std::string MODUS_TOLLENS{"MT"};
}

bool isValid(Proof *newline);
bool isValidPremise(Proof *newline);
bool isValidAndIntroduction(Proof *newline);
bool isValidAndElimination1(Proof *newline);
bool isValidAndElimnation2(Proof *newline);
bool isValidOrIntroduction1(Proof *newline);
bool isValidOrIntroduction2(Proof *newline);
bool isValidImpliesElimination(Proof *newline);
bool isValidModusTollens(Proof *newline);

#endif
