#include <stdio.h>

// C version
int findMax_c(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// NASM function declaration
extern int findMax(int* arr, int size);

int main() {
    int arr[] = {5, 12, 3, 99, 1, 42};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max_c = findMax_c(arr, size);
    int max_asm = findMax(arr, size);

    printf("Max value (C):    %d\n", max_c);
    printf("Max value (NASM): %d\n", max_asm);

    return 0;
}

