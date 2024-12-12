#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Priority Queue structure
typedef struct {
    int size;
    int arr[MAX];
} PriorityQueue;

// Function prototypes
void priorityQueueInsert(PriorityQueue *q, int value);
int priorityQueueRemove(PriorityQueue *q);
void displayPriorityQueue(PriorityQueue *q);

int main() {
    PriorityQueue pq = { 0 };
    int choice, value;

    while(1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert into Priority Queue\n2. Remove from Priority Queue\n");
        printf("3. Display Priority Queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert into Priority Queue: ");
                scanf("%d", &value);
                priorityQueueInsert(&pq, value);
                break;

            case 2:
                value = priorityQueueRemove(&pq);
                if (value != -1) {
                    printf("Removed from Priority Queue: %d\n", value);
                }
                break;

            case 3:
                displayPriorityQueue(&pq);
                break;

            case 4:
                exit(0);
        }
    }

    return 0;
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

// Display Priority Queue
void displayPriorityQueue(PriorityQueue *q) {
    if (q->size == 0) {
        printf("Priority Queue is empty.\n");
    } else {
        printf("Priority Queue: ");
        for (int i = 0; i < q->size; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}
