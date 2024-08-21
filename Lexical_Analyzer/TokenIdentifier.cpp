#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

int isKeyword(const char buffer[]) {
    const char *KeywordArray[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", 
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", 
        "register", "return", "short", "signed", "sizeof", "static", "struct", 
        "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    int numKeywords = sizeof(KeywordArray) / sizeof(KeywordArray[0]);

    for (int i = 0; i < numKeywords; ++i) {
        if (strcmp(KeywordArray[i], buffer) == 0) {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}

int main() {
    char ch, buffer[15];
    const char Operators[] = "+-*/%=";
    ifstream fin("myProgramCode.txt");
    int j = 0;

    if (!fin.is_open()) {
        cout << "Error while opening the file!\n";
        return 1;
    }

    while (fin.get(ch)) {
        bool isOperator = false;

        // Check for operators
        for (int i = 0; i < strlen(Operators); ++i) {
            if (ch == Operators[i]) {
                cout << ch << " is an operator\n";
                isOperator = true;
                break;
            }
        }

        if (isOperator) continue;

        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer)) {
                cout << buffer << " is a Keyword!\n";
            } else {
                cout << buffer << " is an Identifier!\n";
            }
        }
    }

    // Check the last buffer if it has any content
    if (j > 0) {
        buffer[j] = '\0';
        if (isKeyword(buffer)) {
            cout << buffer << " is a Keyword!\n";
        } else {
            cout << buffer << " is an Identifier!\n";
        }
    }

    fin.close();
    return 0;
}
