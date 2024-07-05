/* Code to identify operators in a given string and determine if the string represents an arithmetic equation, an inequality, or neither. */

#include <iostream>
#include <string>
#include <unordered_set>
// Operations on the unordered_set take constant time O(1) on an average which can go up to linear time O(n) in the worst case


using namespace std;

void findOperators(const string &inputString) {
    // Define the set of operators
    unordered_set<char> operators = {'+', '-', '*', '/', '=', '%', '<', '>'};
    unordered_set<char> equalityOperators = {'='};  // To determine if the string represents an arithmetic equation.
    unordered_set<char> inequalityOperators = {'<', '>'};  // To determine if the string represents an inequality.

    // Initialize arrays to store the operators found
    char FoundOperators[100];
    char FoundEquality[100];
    char FoundInequality[100];
    int FoundOperatorsCount = 0;
    int FoundEqualityCount = 0;
    int FoundInequalityCount = 0;

    // Iterate over each character in the input string
    for (char ch : inputString) {
        if (operators.find(ch) != operators.end()) {
            FoundOperators[FoundOperatorsCount++] = ch;
            if (equalityOperators.find(ch) != equalityOperators.end()) {
                FoundEquality[FoundEqualityCount++] = ch;
            }
            if (inequalityOperators.find(ch) != inequalityOperators.end()) {
                FoundInequality[FoundInequalityCount++] = ch;
            }
        }
    }

    // Determine if the input string is an equation or inequality
    string equationType;
    if (FoundInequalityCount > 0) {
        equationType = "Inequality";
    } else if (FoundEqualityCount > 0) {
        equationType = "Arithmetic Equation";
    } else {
        equationType = "Neither an Arithmetic Equation nor an Inequality";
    }

    // Print the found operators and their positions
    for (int i = 0; i < FoundOperatorsCount; ++i) {
        cout << "Operator " << (i + 1) << " : " << FoundOperators[i] << endl;
    }

    // Print the total number of operators found
    cout << "Number of operators = " << FoundOperatorsCount << endl;
    cout << "The input string is an " << equationType << endl;
}

int main() {
    string inputString = "2 * 9 + (10 / 5) = 20";
    cout<<"Input String: "<<inputString<<endl;
    findOperators(inputString);
    return 0;
}
