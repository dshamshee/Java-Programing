#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>  // Include this header for strcpy

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char items[MAX][MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, char* str) {
    if (s->top < MAX - 1) {
        s->top++;
        strcpy(s->items[s->top], str);  // Copy string to stack
    }
}

// Function to pop an element from the stack
void pop(Stack* s, char* str) {
    if (!isEmpty(s)) {
        strcpy(str, s->items[s->top]);  // Copy string from stack
        s->top--;
    }
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix expression to infix
void postfixToInfix(char* postfix, char* infix) {
    Stack s;
    initStack(&s);
    char temp1[MAX], temp2[MAX], temp[MAX];

    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(current)) {
            temp[0] = current;
            temp[1] = '\0';
            push(&s, temp);
        }
        // If the character is an operator
        else if (isOperator(current)) {
            // Pop two operands from the stack
            pop(&s, temp1);
            pop(&s, temp2);

            // Create a new string for the infix expression
            sprintf(temp, "(%s%c%s)", temp2, current, temp1);
            push(&s, temp);
        }
    }

    // The result will be the only element left in the stack
    pop(&s, infix);
}

int main() {
    char postfix[MAX], infix[MAX];
    
    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    
    postfixToInfix(postfix, infix);
    
    printf("Infix expression: %s\n", infix);
    
    return 0;
}
