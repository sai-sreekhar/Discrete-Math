#ifndef VALIDATEPROOF_H
#define VALIDATEPROOF_H

#include <vector>
#include "BinaryTree.h"

// This is the Proof class.
class Proof
{
public:
    // The line number for this line of proof
    int lineNumber;
    // The parse tree for this line of proof
    BinaryTree *parseTree;
    // The rule used to prove this line of proof
    std::string rule;
    // The first line of proof used to prove this line of proof
    Proof *line1;
    // The second line of proof used to prove this line of proof
    Proof *line2;
    // Whether the formula on this line of proof is valid
    bool isValidFormula;

    // Constructor
    Proof(int lineNumber, std::vector<std::string> parts, std::vector<Proof *> prev_lines);
};

// Parse the input line, returning a Proof object
Proof *parseLine(std::string s, int lineNumber, std::vector<Proof *> prev_lines);

// Validate the proof, printing out the error messages
void validateProof();

#endif
