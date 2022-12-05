#ifndef VALIDATEPROOF_H
#define VALIDATEPROOF_H

#include <vector>
#include "BinaryTree.h"

class Proof
{
public:
    int lineNumber;
    BinaryTree *formula;
    std::string ruleLiteral;
    Proof *line1;
    Proof *line2;
    bool isValidFormula;

    Proof(int lineNumber, std::vector<std::string> parts, std::vector<Proof *> prev_lines);
};

Proof *parseLine(std::string s, int lineNumber, std::vector<Proof *> prev_lines);

void validateProof();

#endif
