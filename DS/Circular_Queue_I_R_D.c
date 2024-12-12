#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Circular Queue structure
typedef struct {
    int front, rear;
    int arr[MAX];
} CircularQueue;

// Function prototypes
void circularQueueInsert(CircularQueue *q, int value);
int circularQueueRemove(CircularQueue *q);
void displayCircularQueue(CircularQueue *q);

int main() {
    CircularQueue cq = { -1, -1 };
    int choice, value;

    while(1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert into Circular Queue\n2. Remove from Circular Queue\n");
        printf("3. Display Circular Queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert into Circular Queue: ");
                scanf("%d", &value);
                circularQueueInsert(&cq, value);
                break;

            case 2:
                value = circularQueueRemove(&cq);
                if (value != -1) {
                    printf("Removed from Circular Queue: %d\n", value);
                }
                break;

            case 3:
                displayCircularQueue(&cq);
                break;

            case 4:
                exit(0);
        }
    }

    return 0;
}

// Circular Queue Insert
void circularQueueInsert(CircularQueue *q, int value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Circular Queue is full.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("Inserted %d into Circular Queue\n", value);
    }
}

// Circular Queue Remove
int circularQueueRemove(CircularQueue *q) {
    if (q->front == -1) {
        printf("Circular Queue is empty.\n");
        return -1;
    } else {
        int removed = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Reset queue
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return removed;
    }
}

// Display Circular Queue
void displayCircularQueue(CircularQueue *q) {
    if (q->front == -1) {
        printf("Circular Queue is empty.\n");
    } else {
        int i = q->front;
        printf("Circular Queue: ");
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->arr[q->rear]);
    }
}
