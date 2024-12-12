#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Deque structure
typedef struct {
    int front, rear;
    int arr[MAX];
} Deque;

// Function prototypes
void insertRear(Deque *dq, int value);
void insertFront(Deque *dq, int value);
int deleteFront(Deque *dq);
int deleteRear(Deque *dq);
void displayDeque(Deque *dq);

void inputRestrictedMenu();
void outputRestrictedMenu();

int main() {
    int choice;
    while (1) {
        printf("\nChoose Deque type:\n");
        printf("1. Input Restricted Deque\n");
        printf("2. Output Restricted Deque\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputRestrictedMenu();
                break;
            case 2:
                outputRestrictedMenu();
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}

// Input Restricted Deque Menu
void inputRestrictedMenu() {
    Deque dq = { -1, -1 };
    int choice, value;

    while (1) {
        printf("\nInput Restricted Deque Operations:\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Display\n");
        printf("5. Back to Main Menu\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at Rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;

            case 2:
                value = deleteFront(&dq);
                if (value != -1) {
                    printf("Deleted from Front: %d\n", value);
                }
                break;

            case 3:
                value = deleteRear(&dq);
                if (value != -1) {
                    printf("Deleted from Rear: %d\n", value);
                }
                break;

            case 4:
                displayDeque(&dq);
                break;

            case 5:
                return;
        }
    }
}

// Output Restricted Deque Menu
void outputRestrictedMenu() {
    Deque dq = { -1, -1 };
    int choice, value;

    while (1) {
        printf("\nOutput Restricted Deque Operations:\n");
        printf("1. Insert at Rear\n");
        printf("2. Insert at Front\n");
        printf("3. Delete from Front\n");
        printf("4. Display\n");
        printf("5. Back to Main Menu\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at Rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;

            case 2:
                printf("Enter value to insert at Front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;

            case 3:
                value = deleteFront(&dq);
                if (value != -1) {
                    printf("Deleted from Front: %d\n", value);
                }
                break;

            case 4:
                displayDeque(&dq);
                break;

            case 5:
                return;
        }
    }
}

// Insert at Rear
void insertRear(Deque *dq, int value) {
    if ((dq->rear + 1) % MAX == dq->front) {
        printf("Deque is full.\n");
    } else {
        if (dq->front == -1) {
            dq->front = 0;
        }
        dq->rear = (dq->rear + 1) % MAX;
        dq->arr[dq->rear] = value;
        printf("Inserted %d at Rear\n", value);
    }
}

// Insert at Front
void insertFront(Deque *dq, int value) {
    if ((dq->rear + 1) % MAX == dq->front) {
        printf("Deque is full.\n");
    } else {
        if (dq->front == -1) {
            dq->front = dq->rear = 0;
        } else {
            dq->front = (dq->front - 1 + MAX) % MAX;
        }
        dq->arr[dq->front] = value;
        printf("Inserted %d at Front\n", value);
    }
}

// Delete from Front
int deleteFront(Deque *dq) {
    if (dq->front == -1) {
        printf("Deque is empty.\n");
        return -1;
    } else {
        int value = dq->arr[dq->front];
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1; // Reset deque
        } else {
            dq->front = (dq->front + 1) % MAX;
        }
        return value;
    }
}

// Delete from Rear
int deleteRear(Deque *dq) {
    if (dq->rear == -1) {
        printf("Deque is empty.\n");
        return -1;
    } else {
        int value = dq->arr[dq->rear];
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1; // Reset deque
        } else {
            dq->rear = (dq->rear - 1 + MAX) % MAX;
        }
        return value;
    }
}

// Display Deque
void displayDeque(Deque *dq) {
    if (dq->front == -1) {
        printf("Deque is empty.\n");
    } else {
        int i = dq->front;
        printf("Deque: ");
        while (i != dq->rear) {
            printf("%d ", dq->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", dq->arr[dq->rear]);
    }
}
