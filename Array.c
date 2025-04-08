#include <stdio.h>

void insertion(int arr[], int *Size);
void deletion(int arr[], int *Size);
void linearSearch(int arr[], int Size);
void binarySearch(int arr[], int Size);

int main() {
    int arr[20], Size = 10, Choice;

    printf("Enter 10 elements for the array:\n");
    for (int i = 0; i < Size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for (int i = 0; i < Size; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\nMenu\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Linear Search\n");
    printf("4. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &Choice);

    switch (Choice) {
        case 1:
            insertion(arr, &Size);
            break;
        case 2:
            deletion(arr, &Size);
            break;
        case 3:
            linearSearch(arr, Size);
            break;
        case 4:
            binarySearch(arr, Size);
            break;
        default:
            printf("Invalid Choice\n");
    }

    return 0;
}

// Function for insertion
void insertion(int arr[], int *Size) {
    int pos, val;
    printf("Enter the position to insert (0 to %d): ", *Size);
    scanf("%d", &pos);

    if (pos < 0 || pos > *Size) {
        printf("Invalid Position\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &val);

    for (int i = *Size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    (*Size)++;

    printf("Array after insertion:\n");
    for (int i = 0; i < *Size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// Function for deletion
void deletion(int arr[], int *Size) {
    if (*Size == 0) {
        printf("Array is empty!\n");
        return;
    }

    int pos;
    printf("Enter the position to delete (0 to %d): ", *Size - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *Size) {
        printf("Invalid Position\n");
        return;
    }

    for (int i = pos; i < *Size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*Size)--;

    printf("Array after deletion:\n");
    for (int i = 0; i < *Size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// Function for linear search
void linearSearch(int arr[], int Size) {
    int val, found = 0;
    printf("Enter the value to search: ");
    scanf("%d", &val);

    for (int i = 0; i < Size; i++) {
        if (arr[i] == val) {
            printf("Value found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Value not found\n");
    }
}

// Function for binary search
void binarySearch(int arr[], int Size) {
    int val, low = 0, high = Size - 1, mid, found = 0;

    printf("Enter the value to search: ");
    scanf("%d", &val);

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == val) {
            printf("Value found at index %d\n", mid);
            found = 1;
            break;
        } else if (val < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!found) {
        printf("Value not found\n");
    }
}