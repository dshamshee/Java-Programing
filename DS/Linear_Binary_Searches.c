#include <stdio.h>

// Linear Search
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Element found, return index
        }
    }
    return -1; // Element not found
}

// Binary Search (assuming array is sorted)
int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Element found at mid
        }
        else if (arr[mid] < key) {
            low = mid + 1; // Search the right half
        }
        else {
            high = mid - 1; // Search the left half
        }
    }
    return -1; // Element not found
}

int main() {
    int n, key, choice;

    // Input for array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    printf("\nChoose search method:\n");
    printf("1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int result = linear_search(arr, n, key);
        if (result == -1) {
            printf("Element not found using Linear Search.\n");
        } else {
            printf("Element found at index %d using Linear Search.\n", result);
        }
    } 
    else if (choice == 2) {
        // Binary Search requires sorted array
        int result = binary_search(arr, n, key);
        if (result == -1) {
            printf("Element not found using Binary Search.\n");
        } else {
            printf("Element found at index %d using Binary Search.\n", result);
        }
    } 
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}
