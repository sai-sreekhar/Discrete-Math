#ifndef RULES_H
#define RULES_H
#include <string>
#include "Operators.h"
#include "ValidateProof.h"

namespace verbs
{
    // The introduction of a new name, by the user or the compiler.
    const char INTRODUCTION{'i'}; // 'i' for 'introduce'.

    // The elimination of a name, by the user or the compiler.
    const char ELIMINATION{'e'}; // 'e' for 'eliminate'.
}

namespace ruleLiterals
{
    using namespace operators;
    const std::string PREMISE{"P"};
    const std::string AND_INTRODUCIION{AND_OPERATOR, verbs::INTRODUCTION};
    // P & Q -> P
    // Premise of AND_ELIMINATION_1
    const std::string AND_ELMINATION_1{AND_OPERATOR, verbs::ELIMINATION, '1'};
    // P & Q -> Q
    // Premise of AND_ELIMINATION_2
    const std::string AND_ELIMNATION_2{AND_OPERATOR, verbs::ELIMINATION, '2'};
    // P -> P | Q
    // Premise of OR_INTRODUCTION_1
    const std::string OR_INTRODUCTION_1{OR_OPERATOR, verbs::INTRODUCTION, '1'};
    // Q -> P | Q
    // Premise of OR_INTRODUCTION_2
    const std::string OR_INTRODUCTION_2{OR_OPERATOR, verbs::INTRODUCTION, '2'};
    // P -> Q
    // Premise of IMPLIES_ELIMINATION
    const std::string IMPLIES_ELIMINATION{IMPLIES_OPERATOR, verbs::ELIMINATION};
    // ~Q -> ~P
    // Premise of MODUS_TOLLENS
    const std::string MODUS_TOLLENS{"MT"};
}

bool isValid(Proof *newline);
bool isValidPremise(Proof *newline);
bool isValidAndIntroduction(Proof *newline);
bool isValidAndElimination1(Proof *newline);
bool isValidAndElimination2(Proof *newline);
bool isValidOrIntroduction1(Proof *newline);
bool isValidOrIntroduction2(Proof *newline);
bool isValidImpliesElimination(Proof *newline);
bool isValidModusTollens(Proof *newline);

#endif
