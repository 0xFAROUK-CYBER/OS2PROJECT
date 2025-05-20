#include <stdio.h>

// NASM version of bubbleSort
extern void bubbleSort(int* arr, int size);

// C version of printArray
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Optional: C version of bubbleSort (for comparison)
void bubbleSort_c(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original (C):     ");
    printArray(arr, size);

    bubbleSort_c(arr, size);
    printf("Sorted (C):       ");
    printArray(arr, size);

    printf("Original (NASM):  ");
    printArray(arr2, size);

    bubbleSort(arr2, size);
    printf("Sorted (NASM):    ");
    printArray(arr2, size);

    return 0;
}

