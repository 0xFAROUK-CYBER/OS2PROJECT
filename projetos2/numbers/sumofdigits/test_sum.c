#include <stdio.h>
#include <time.h>

extern long long sum_of_digit(long long n);

long long sum_of_digit_c(long long n) {
    long long sum = 0;
    if (n < 0) n = -n;  // Handle negative numbers
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    long long input = 1234567890;
    long long result_c, result_asm;
    clock_t start, end;
    double time_c, time_asm;
    int iterations = 1000000;

    // Warm up (optional)
    result_c = sum_of_digit_c(input);
    result_asm = sum_of_digit(input);

    // Benchmark C function
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result_c = sum_of_digit_c(input);
    }
    end = clock();
    time_c = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Benchmark ASM function
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result_asm = sum_of_digit(input);
    }
    end = clock();
    time_asm = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("C function: Result = %lld, Time = %f seconds\n", result_c, time_c);
    printf("ASM function: Result = %lld, Time = %f seconds\n", result_asm, time_asm);
    printf("Speed ratio (C/ASM): %f\n", time_c/time_asm);

    return 0;
}
