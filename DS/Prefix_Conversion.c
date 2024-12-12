#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Helper functions
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    char stack[MAX];
    int top = -1;
    int k = 0;

    // Reverse the infix expression
    reverse(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Process the reversed infix expression
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            // If the character is an operand, add it to the prefix expression
            prefix[k++] = c;
        } else if (c == '(') {
            // Push '(' to the stack
            stack[++top] = c;
        } else if (c == ')') {
            // Pop from the stack until '(' is found
            while (top != -1 && stack[top] != '(') {
                prefix[k++] = stack[top--];
            }
            top--; // Remove '(' from the stack
        } else if (isOperator(c)) {
            // Pop operators with higher or equal precedence from the stack
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                prefix[k++] = stack[top--];
            }
            stack[++top] = c; // Push the current operator to the stack
        }
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        prefix[k++] = stack[top--];
    }

    prefix[k] = '\0';

    // Reverse the prefix expression to get the correct order
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
