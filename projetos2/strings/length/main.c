#include <stdio.h>

// Declare the NASM function
extern int stringLength(char* str);

int main() {
    char str[] = "CyberSecurity";

    int len = stringLength(str);
    printf("Length of '%s' is: %d\n", str, len);

    return 0;
}

