/* Code to check whether a given input string is a keyword in the C or C++ */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string keyword[32] = {
        "auto", "double", "int", "struct", "break", "else", "long",
        "switch", "case", "enum", "register", "typedef", "char",
        "extern", "return", "union", "const", "float", "short",
        "unsigned", "continue", "for", "signed", "void", "default",
        "goto", "sizeof", "volatile", "do", "if", "static", "while"
    };

    string str;
    cout << "Enter a string: "; // Would be conventional to use a single word.
    getline(cin, str);

    bool isKeyword = false;
    for (int i = 0; i < 32; i++) {
        if (str == keyword[i]) {
            isKeyword = true;
            break;
        }
    }

    if (isKeyword)
        cout << str << " is a keyword" << endl;
    else
        cout << str << " is not a keyword" << endl;

    return 0;
}
