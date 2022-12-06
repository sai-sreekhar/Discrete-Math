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

    // If there are any parts, convert the first part to a postfix expression and parse it into a tree
    if (!parts.empty())
    {
        string postfix = infixToPostfix(parts[0]);
        parseTree = postfixExpressionToTree(&postfix);
    }

    // If there are more than 1 parts, the second part is the rule
    if (parts.size() > 1)
    {
        rule = parts[1];
    }

    // The third part is the first line number, if it exists
    int lineNumber1;
    if (parts.size() > 2 and lineNumber > (lineNumber1 = stoi(parts[2])))
    {
        line1 = previousLines[lineNumber1 - 1];
    }
    else
    {
        line1 = nullptr;
    }

    // The fourth part is the second line number, if it exists
    int lineNumber2;
    if (parts.size() > 3 and lineNumber > (lineNumber2 = stoi(parts[3])))
    {
        line2 = previousLines[lineNumber2 - 1];
    }
    else
    {
        line2 = nullptr;
    }

    // Determine if the line is a valid formula
    isValidFormula = isValid(this);
}

// Parse a line of the proof
// s is the line to parse
// lineNumber is the line number of this line
// previousLines is a vector of all previous lines in the proof
Proof *parseLine(string s, int lineNumber, vector<Proof *> previousLines)
{
    // Add a slash to the end of the string
    // This makes the while loop below work better
    s.push_back('/');

    // Create a string to store each part of the line
    string part;

    // Create a vector to store each part of the line
    vector<string> parts;

    // Create a string stream to read the line
    istringstream iss(s);

    // Read the line until the string stream runs out of characters
    while (getline(iss, part, '/'))
    {
        // Add each part to the vector
        parts.push_back(part);
    }

    // Return a new Proof object for this line
    return new Proof(lineNumber, parts, previousLines);
}

// Validate a proof entered by the user.
void validateProof()
{
    // Get the number of lines in the proof.
    int n;
    cout << "Enter number of lines in proof: ";
    cin >> n;
    // Create a vector to store the proof.
    vector<Proof *> proof;
    // Get the lines of the proof.
    cout << "Enter the lines of the proof: \n";
    cin.ignore(1);
    for (int i = 1; i <= n; i++)
    {
        // Get the line of the proof.
        string line;
        cout << i << ": ";
        getline(cin, line);
        // Parse the line into a Proof object.
        proof.push_back(parseLine(line, i, proof));
    }

    // Check each line in the proof.
    for (auto proofline : proof)
    {
        // If the line is not a valid formula, print an error message and return.
        if (!(proofline->isValidFormula))
        {
            cout << "Invalid proof. First error at line number " << proofline->lineNumber << ".\n";
            return;
        }
    }
    // If all lines are valid, print a success message.
    cout << "Valid proof\n";
}
