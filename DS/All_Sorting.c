#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Shell Sort
void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Quick Sort (using Lomuto partition scheme)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Heap Sort (using max-heap)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Radix Sort
int get_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void counting_sort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int n) {
    int max = get_max(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(arr, n, exp);
    }
}

int main() {
    int arr[MAX_SIZE], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    int arr1[MAX_SIZE];
    for (int i = 0; i < n; i++) arr1[i] = arr[i];
    printf("\nBubble Sort:\n");
    bubble_sort(arr1, n);
    print_array(arr1, n);

    // Selection Sort
    int arr2[MAX_SIZE];
    for (int i = 0; i < n; i++) arr2[i] = arr[i];
    printf("\nSelection Sort:\n");
    selection_sort(arr2, n);
    print_array(arr2, n);

    // Insertion Sort
    int arr3[MAX_SIZE];
    for (int i = 0; i < n; i++) arr3[i] = arr[i];
    printf("\nInsertion Sort:\n");
    insertion_sort(arr3, n);
    print_array(arr3, n);

    // Shell Sort
    int arr4[MAX_SIZE];
    for (int i = 0; i < n; i++) arr4[i] = arr[i];
    printf("\nShell Sort:\n");
    shell_sort(arr4, n);
    print_array(arr4, n);

    // Quick Sort
    int arr5[MAX_SIZE];
    for (int i = 0; i < n; i++) arr5[i] = arr[i];
    printf("\nQuick Sort:\n");
    quick_sort(arr5, 0, n-1);
    print_array(arr5, n);

    // Heap Sort
    int arr6[MAX_SIZE];
    for (int i = 0; i < n; i++) arr6[i] = arr[i];
    printf("\nHeap Sort:\n");
    heap_sort(arr6, n);
    print_array(arr6, n);

    // Merge Sort
    int arr7[MAX_SIZE];
    for (int i = 0; i < n; i++) arr7[i] = arr[i];
    printf("\nMerge Sort:\n");
    merge_sort(arr7, 0, n-1);
    print_array(arr7, n);

    // Radix Sort
    int arr8[MAX_SIZE];
    for (int i = 0; i < n; i++) arr8[i] = arr[i];
    printf("\nRadix Sort:\n");
    radix_sort(arr8, n);
    print_array(arr8, n);

    return 0;
}
