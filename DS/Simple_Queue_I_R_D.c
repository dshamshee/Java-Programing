#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Simple Queue structure
typedef struct {
    int front, rear;
    int arr[MAX];
} SimpleQueue;

// Function prototypes
void simpleQueueInsert(SimpleQueue *q, int value);
int simpleQueueRemove(SimpleQueue *q);
void displaySimpleQueue(SimpleQueue *q);

int main() {
    SimpleQueue sq = { -1, -1 };
    int choice, value;

    while(1) {
        printf("\nSimple Queue Operations:\n");
        printf("1. Insert into Simple Queue\n2. Remove from Simple Queue\n");
        printf("3. Display Simple Queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert into Simple Queue: ");
                scanf("%d", &value);
                simpleQueueInsert(&sq, value);
                break;

            case 2:
                value = simpleQueueRemove(&sq);
                if (value != -1) {
                    printf("Removed from Simple Queue: %d\n", value);
                }
                break;

            case 3:
                displaySimpleQueue(&sq);
                break;

            case 4:
                exit(0);
        }
    }

    return 0;
}

// Simple Queue Insert
void simpleQueueInsert(SimpleQueue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Simple Queue is full.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;
        printf("Inserted %d into Simple Queue\n", value);
    }
}

// Simple Queue Remove
int simpleQueueRemove(SimpleQueue *q) {
    if (q->front == -1) {
        printf("Simple Queue is empty.\n");
        return -1;
    } else {
        int removed = q->arr[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1; // Reset queue
        }
        return removed;
    }
}

// Display Simple Queue
void displaySimpleQueue(SimpleQueue *q) {
    if (q->front == -1) {
        printf("Simple Queue is empty.\n");
    } else {
        printf("Simple Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}
