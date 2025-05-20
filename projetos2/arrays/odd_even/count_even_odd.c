#include <stdio.h>
#include <time.h>

// Declaration of the assembly function
extern void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount);

// C implementation for benchmarking
void countEvenOddC(int arr[], int size, int* evenCount, int* oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    for (int i = 0; i < size; i++) {
        if ((arr[i] & 1) == 0)
            (*evenCount)++;
        else
            (*oddCount)++;
    }
}

// Benchmark helper function
void benchmark(void (*func)(int[], int, int*, int*), int arr[], int size, const char* label) {
    int evenCount, oddCount;
    clock_t start = clock();
    func(arr, size, &evenCount, &oddCount);
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%s => Even count: %d, Odd count: %d, Time: %f seconds\n", label, evenCount, oddCount, elapsed);
}

int main() {
    int size = 1000000;
    int *arr = malloc(size * sizeof(int));

    // Initialize array with some values
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    printf("Benchmarking even/odd counting functions:\n");

    benchmark(countEvenOddC, arr, size, "C function");
    benchmark(countEvenOdd, arr, size, "Assembly function");

    free(arr);
    return 0;
}

