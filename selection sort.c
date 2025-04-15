#include <stdio.h>
#include <stdlib.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap arr[min] and arr[i]
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check for valid size
    if (size <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    // Free the allocated memory
    free(arr);

    return 0;
}
