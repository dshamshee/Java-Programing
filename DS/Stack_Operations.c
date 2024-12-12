#include <stdio.h>
#define MAX 100  // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
        return -1; // Return -1 to indicate an error
    }
    int poppedValue = stack[top--];
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to peek the top element of the stack
int peek() {
    if (top == -1) {
        printf("Stack is empty! No top element.\n");
        return -1; // Return -1 to indicate an error
    }
    printf("Top element is %d.\n", stack[top]);
    return stack[top];
}

// Function to display the elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
