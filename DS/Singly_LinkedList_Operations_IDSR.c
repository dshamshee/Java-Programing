#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

// Function prototypes
void insert(Node **head, int value);
void delete(Node **head, int value);
void search(Node *head, int value);
void reverse(Node **head);
void displayList(Node *head);

int main() {
    Node *head = NULL;
    int choice, value;

    while (1) {
        printf("\nChoose Operation:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Reverse\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&head, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;

            case 4:
                reverse(&head);
                printf("List reversed.\n");
                break;

            case 5:
                printf("Current list: ");
                displayList(head);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Insert a value into the linked list
void insert(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    printf("Inserted %d into the list.\n", value);
}

// Delete a value from the linked list
void delete(Node **head, int value) {
    Node *temp = *head, *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Deleted %d from the list.\n", value);
}

// Search for a value in the linked list
void search(Node *head, int value) {
    Node *current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        current = current->next;
        position++;
    }

    printf("Value %d not found in the list.\n", value);
}

// Reverse the linked list
void reverse(Node **head) {
    Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
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