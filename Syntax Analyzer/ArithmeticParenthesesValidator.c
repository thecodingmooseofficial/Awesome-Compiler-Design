/* C Code that detect whether the given mathematical expression is properly parenthesized or not. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int index, length, parentheses_balance = 0;
    char myArray[100];

    printf("Enter the equation: ");
    scanf("%s", myArray);
    length = strlen(myArray);

    if (length == 0) {
        printf("Invalid Input!\n");
        return 0;
    }

    for (index = 0; index < length; index++) {
        if (myArray[index] == '(') {
            parentheses_balance++;
        } else if (myArray[index] == ')') {
            parentheses_balance--;
            if (parentheses_balance < 0) {
                printf("Equation not properly Parenthesized!\n");
                return 0;
            }
        } else if (myArray[index] == '*' || myArray[index] == '/' || myArray[index] == '+' || myArray[index] == '-') {
            // Check for operators in invalid positions
            if (index == 0 || index == length - 1 ||
                (!isalnum(myArray[index - 1]) && myArray[index - 1] != ')' ) ||
                (!isalnum(myArray[index + 1]) && myArray[index + 1] != '(')) {
                printf("Invalid Operator Sequence!\n");
                return 0;
            }
        } else if (!isalnum(myArray[index]) && myArray[index] != '(' && myArray[index] != ')' && myArray[index] != '*' && myArray[index] != '/' && myArray[index] != '+' && myArray[index] != '-') {
            // Check for invalid characters
            printf("Invalid Characters!\n");
            return 0;
        }
    }

    // Ensure no extra open or close parentheses remain
    if (parentheses_balance != 0) {
        printf("Equation is not properly parenthesized!\n");
        return 0;
    }

    printf("The Equation is properly parenthesized!\n");
    return 0;
}
