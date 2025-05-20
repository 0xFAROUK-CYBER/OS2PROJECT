#include <stdio.h>

// Declare NASM function
extern void removeWhitespaces(char* str);

int main() {
    char str[] = "Cyber Security Project";

    printf("Before: '%s'\n", str);
    removeWhitespaces(str);
    printf("After:  '%s'\n", str);

    return 0;
}


