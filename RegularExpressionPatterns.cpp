#include <iostream>
#include <cstring>

#define MATCH cout << "\nThe Text Matches The Regular Expression"
#define NOTMATCH cout << "\nThe Text Doesn't match the Regular Expression"

using namespace std;

char reg[20], text[20];

bool matchRegex(char *reg, char *text) {
    if (*reg == '\0') return *text == '\0';

    if (reg[1] == '*') {
        return matchRegex(reg + 2, text) || (*text != '\0' && (*reg == '.' || *reg == *text) && matchRegex(reg, text + 1));
    }

    if (reg[1] == '+') {
        return (*text != '\0' && (*reg == '.' || *reg == *text) && (matchRegex(reg + 2, text + 1) || matchRegex(reg, text + 1)));
    }

    if (reg[1] == '?') {
        return matchRegex(reg + 2, text) || (*text != '\0' && (*reg == '.' || *reg == *text) && matchRegex(reg + 2, text + 1));
    }

    if (*reg == '^') {
        return matchRegex(reg + 1, text);
    }

    if (*reg == '$') {
        return *text == '\0' && *(reg + 1) == '\0';
    }

    if (*reg == '.' || *reg == *text) {
        return matchRegex(reg + 1, text + 1);
    }

    return false;
}

int main() {
    char ans;

    do {
        cout << "\nEnter the Regular Expression: ";
        cin.getline(reg, 20);

        cout << "\nEnter the text: ";
        cin.getline(text, 20);

        if (reg[0] == '*') {
            cout << "\nInvalid Regular Expression!";
        } else {
            if (matchRegex(reg, text)) {
                MATCH;
            } else {
                NOTMATCH;
            }
        }

        cout << "\nDo you want to continue?(Y/N)";
        cin >> ans;
        cin.ignore();  // Ignore remaining newline character
    } while (ans == 'Y' || ans == 'y');

    return 0;
}
