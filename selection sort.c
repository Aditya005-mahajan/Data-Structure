#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i; 

        for (j = i + 1; j < n; j++) { 
            
            if (arr[j] < arr[min]) {
               
                min = j;
            }
        }

    
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); 
    }
    
    selectionSort(arr, size);
    
    printf("Sorted array:\n");
    printArray(arr, size);
    
    return 0;
}
