#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* s, char c) {
    if (!isFull(s)) {
        s->items[++(s->top)] = c;
    }
}

// Function to pop an element from the stack
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1;  // Return -1 if stack is empty
}

// Function to peek the top element of the stack
char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(current)) {
            postfix[k++] = current;
        }
        // If the character is '(', push it to the stack
        else if (current == '(') {
            push(&s, current);
        }
        // If the character is ')', pop and append operators to postfix until '(' is found
        else if (current == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Pop '(' from stack
        }
        // If the character is an operator
        else if (isOperator(current)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(current)) {
                postfix[k++] = pop(&s);
            }
            push(&s, current);
        }
    }

    // Pop any remaining operators in the stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
