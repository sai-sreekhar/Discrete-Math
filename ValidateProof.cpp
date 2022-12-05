#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Rules.h"
#include "ValidateProof.h"
#include "TreeConstructor.h"

using namespace std;

Proof::Proof(int lineNumber, vector<string> parts, vector<Proof *> previousLines)
{
    this->lineNumber = lineNumber;

    if (!parts.empty())
    {
        string postfix = infixToPostfix(parts[0]);
        parseTree = postfixExpressionToTree(&postfix);
    }
    if (parts.size() > 1)
    {
        rule = parts[1];
    }
    int lineNumber1, lineNumber2;
    if (parts.size() > 2 and lineNumber > (lineNumber1 = stoi(parts[2])))
    {
        line1 = previousLines[lineNumber1 - 1];
    }
    else
    {
        line1 = nullptr;
    }

    if (parts.size() > 3 and lineNumber > (lineNumber2 = stoi(parts[3])))
    {
        line2 = previousLines[lineNumber2 - 1];
    }
    else
    {
        line2 = nullptr;
    }

    isValidFormula = isValid(this);
}

Proof *parseLine(string s, int lineNumber, vector<Proof *> previousLines)
{
    s.push_back('/');
    string part;
    vector<string> parts;
    istringstream iss(s);
    while (getline(iss, part, '/'))
    {
        parts.push_back(part);
    }
    return new Proof(lineNumber, parts, previousLines);
}

void validateProof()
{
    int n;
    cout << "Enter number of lines in proof: ";
    cin >> n;
    vector<Proof *> proof;
    cout << "Enter the lines of the proof: \n";
    cin.ignore(1);
    for (int i = 1; i <= n; i++)
    {
        string line;
        cout << i << ": ";
        getline(cin, line);
        proof.push_back(parseLine(line, i, proof));
    }

    for (auto proofline : proof)
    {
        if (!(proofline->isValidFormula))
        {
            cout << "Invalid proof. First error at line number " << proofline->lineNumber << ".\n";
            return;
        }
    }
    cout << "Valid proof\n";
}
