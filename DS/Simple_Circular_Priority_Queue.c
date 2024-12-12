#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Simple Queue structure
typedef struct {
    int front, rear;
    int arr[MAX];
} SimpleQueue;

// Circular Queue structure
typedef struct {
    int front, rear;
    int arr[MAX];
} CircularQueue;

// Priority Queue structure
typedef struct {
    int size;
    int arr[MAX];
} PriorityQueue;

// Function prototypes
void simpleQueueInsert(SimpleQueue *q, int value);
int simpleQueueRemove(SimpleQueue *q);
void circularQueueInsert(CircularQueue *q, int value);
int circularQueueRemove(CircularQueue *q);
void priorityQueueInsert(PriorityQueue *q, int value);
int priorityQueueRemove(PriorityQueue *q);

int main() {
    // Simple Queue
    SimpleQueue sq = { -1, -1 };
    // Circular Queue
    CircularQueue cq = { -1, -1 };
    // Priority Queue
    PriorityQueue pq = { 0 };

    int choice, value;

    while(1) {
        printf("\nChoose operation:\n");
        printf("1. Insert into Simple Queue\n2. Remove from Simple Queue\n");
        printf("3. Insert into Circular Queue\n4. Remove from Circular Queue\n");
        printf("5. Insert into Priority Queue\n6. Remove from Priority Queue\n");
        printf("7. Exit\n");
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
                printf("Enter value to insert into Circular Queue: ");
                scanf("%d", &value);
                circularQueueInsert(&cq, value);
                break;

            case 4:
                value = circularQueueRemove(&cq);
                if (value != -1) {
                    printf("Removed from Circular Queue: %d\n", value);
                }
                break;

            case 5:
                printf("Enter value to insert into Priority Queue: ");
                scanf("%d", &value);
                priorityQueueInsert(&pq, value);
                break;

            case 6:
                value = priorityQueueRemove(&pq);
                if (value != -1) {
                    printf("Removed from Priority Queue: %d\n", value);
                }
                break;

            case 7:
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

// Priority Queue Insert (Descending order)
void priorityQueueInsert(PriorityQueue *q, int value) {
    if (q->size == MAX) {
        printf("Priority Queue is full.\n");
    } else {
        int i = q->size - 1;
        while (i >= 0 && q->arr[i] < value) {
            q->arr[i + 1] = q->arr[i];
            i--;
        }
        q->arr[i + 1] = value;
        q->size++;
        printf("Inserted %d into Priority Queue\n", value);
    }
}

// Priority Queue Remove
int priorityQueueRemove(PriorityQueue *q) {
    if (q->size == 0) {
        printf("Priority Queue is empty.\n");
        return -1;
    } else {
        int removed = q->arr[0];
        for (int i = 0; i < q->size - 1; i++) {
            q->arr[i] = q->arr[i + 1];
        }
        q->size--;
        return removed;
    }
}
