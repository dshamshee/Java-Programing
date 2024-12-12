#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

// Function prototypes
void insertFIFO(Node **head, Node **tail, int value);
void insertLIFO(Node **head, int value);
void displayList(Node *head);

int main() {
    Node *headFIFO = NULL, *tailFIFO = NULL; // For FIFO
    Node *headLIFO = NULL;                  // For LIFO
    int choice, value;

    while (1) {
        printf("\nChoose Operation:\n");
        printf("1. Insert in FIFO form\n");
        printf("2. Insert in LIFO form\n");
        printf("3. Display FIFO list\n");
        printf("4. Display LIFO list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in FIFO list: ");
                scanf("%d", &value);
                insertFIFO(&headFIFO, &tailFIFO, value);
                break;

            case 2:
                printf("Enter value to insert in LIFO list: ");
                scanf("%d", &value);
                insertLIFO(&headLIFO, value);
                break;

            case 3:
                printf("FIFO list: ");
                displayList(headFIFO);
                break;

            case 4:
                printf("LIFO list: ");
                displayList(headLIFO);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Insert a value into the linked list in FIFO form
void insertFIFO(Node **head, Node **tail, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) { // If the list is empty
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("Inserted %d in FIFO list.\n", value);
}

// Insert a value into the linked list in LIFO form
void insertLIFO(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    printf("Inserted %d in LIFO list.\n", value);
}

// Display the linked list
void displayList(Node *head) {
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