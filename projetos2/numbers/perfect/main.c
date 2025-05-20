#include <stdio.h>

// C implementation
int isPerfect_c(int num) {
    if (num <= 1) return 0;
    int sum = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            sum += i;
    }
    return sum == num;
}

// Declare NASM function
extern int isPerfect(int num); // defined in perfect.asm

int main() {
    int number = 28; // You can change this number for testing

    int result_c = isPerfect_c(number);
    int result_asm = isPerfect(number);

    printf("Is %d a perfect number?\n", number);
    printf("C version:    %s\n", result_c ? "Yes" : "No");
    printf("NASM version: %s\n", result_asm ? "Yes" : "No");

    return 0;
}

