/*  Code to check whether the given input is a comment line(s) or not */

#include <iostream>
#include <string>

using namespace std;

bool isSingleLineComment(const string& input) {
    return input.substr(0, 2) == "//";
}

bool isMultiLineComment(const string& input) {
    return input.substr(0, 2) == "/*" && input.substr(input.size() - 2, 2) == "*/";
}

int main() {
    string input;
    cout << "Enter a line: ";
    getline(cin, input);

    if (isSingleLineComment(input)) {
        cout << "This is a single line comment.\n";
    } else if (isMultiLineComment(input)) {
        cout << "This is a multi line comment.\n";
    } else {
        cout << "This is not a comment.\n";
    }

    return 0;
}
