#include <stdio.h>
#include <string.h>
#include <time.h>

// Declare assembly function
extern void reverseString(char* str);

// C implementation to reverse string in place
void reverseStringC(char* str) {
    int len = strlen(str);
    int i = 0, j = len - 1;
    while (i < j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

// Benchmark function
void benchmark(void (*func)(char*), char* str, const char* label) {
    char buffer[1024];
    strcpy(buffer, str);

    clock_t start = clock();
    func(buffer);
    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%s Result: %s\n", label, buffer);
    printf("%s Execution time: %f seconds\n", label, elapsed);
}

int main() {
    char testStr[] = "Hello Assembly and C!";

    printf("Benchmarking string reversal:\n");

    benchmark(reverseStringC, testStr, "C function");
    benchmark(reverseString, testStr, "Assembly function");

    return 0;
}

