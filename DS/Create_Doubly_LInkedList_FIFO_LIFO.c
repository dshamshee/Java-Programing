#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

// Function prototypes
void insertFIFO(Node **head, Node **tail, int value);
void insertLIFO(Node **head, Node **tail, int value);
void displayListForward(Node *head);
void displayListBackward(Node *tail);

int main() {
    Node *head = NULL, *tail = NULL;
    int choice, value;

    while (1) {
        printf("\nChoose Operation:\n");
        printf("1. Insert in FIFO form\n");
        printf("2. Insert in LIFO form\n");
        printf("3. Display list forward\n");
        printf("4. Display list backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in FIFO list: ");
                scanf("%d", &value);
                insertFIFO(&head, &tail, value);
                break;

            case 2:
                printf("Enter value to insert in LIFO list: ");
                scanf("%d", &value);
                insertLIFO(&head, &tail, value);
                break;

            case 3:
                printf("List (forward): ");
                displayListForward(head);
                break;

            case 4:
                printf("List (backward): ");
                displayListBackward(tail);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Insert a value into the doubly linked list in FIFO form
void insertFIFO(Node **head, Node **tail, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) { // If the list is empty
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }

    printf("Inserted %d in FIFO list.\n", value);
}

// Insert a value into the doubly linked list in LIFO form
void insertLIFO(Node **head, Node **tail, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head == NULL) { // If the list is empty
        *head = *tail = newNode;
    } else {
        (*head)->prev = newNode;
        *head = newNode;
    }

    printf("Inserted %d in LIFO list.\n", value);
}

// Display the doubly linked list forward
void displayListForward(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Display the doubly linked list backward
void displayListBackward(Node *tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = tail;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}
