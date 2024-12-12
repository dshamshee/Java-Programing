#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

// Function prototypes
void insert(Node **last, int value);
void delete(Node **last, int value);
void display(Node *last);

int main() {
    Node *last = NULL;
    int choice, value;

    while (1) {
        printf("\nChoose Operation:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&last, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&last, value);
                break;

            case 3:
                display(last);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to insert a value into the circular linked list
void insert(Node **last, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    if (*last == NULL) { // If the list is empty
        newNode->next = newNode;
        *last = newNode;
    } else { // Insert at the end
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }

    printf("Inserted %d into the list.\n", value);
}

// Function to delete a value from the circular linked list
void delete(Node **last, int value) {
    if (*last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = (*last)->next, *prev = *last;

    do {
        if (current->data == value) {
            if (current == *last && current->next == current) { // Only one node
                *last = NULL;
            } else {
                if (current == *last) {
                    *last = prev;
                }
                prev->next = current->next;
            }
            free(current);
            printf("Deleted %d from the list.\n", value);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != (*last)->next);

    printf("Value %d not found in the list.\n", value);
}

// Function to display the circular linked list
void display(Node *last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = last->next;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != last->next);

    printf("(back to start)\n");
}