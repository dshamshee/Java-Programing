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
void insert(Node **head, Node **tail, int value);
void delete(Node **head, Node **tail, int value);
void search(Node *head, int value);
void reverse(Node **head, Node **tail);
void displayList(Node *head);

int main() {
    Node *head = NULL, *tail = NULL;
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
                insert(&head, &tail, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&head, &tail, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;

            case 4:
                reverse(&head, &tail);
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

// Insert a value into the doubly linked list
void insert(Node **head, Node **tail, int value) {
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

    printf("Inserted %d into the list.\n", value);
}

// Delete a value from the doubly linked list
void delete(Node **head, Node **tail, int value) {
    Node *temp = *head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        *tail = temp->prev;
    }

    free(temp);
    printf("Deleted %d from the list.\n", value);
}

// Search for a value in the doubly linked list
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

// Reverse the doubly linked list
void reverse(Node **head, Node **tail) {
    Node *current = *head, *temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *tail = *head;
        *head = temp->prev;
    }
}

// Display the doubly linked list
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
