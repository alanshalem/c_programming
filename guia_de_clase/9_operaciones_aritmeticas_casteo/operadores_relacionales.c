#include <stdio.h>

int main() {
    int a = 5, b = 10;

    // Greater than operator
    if (a > b) {
        printf("%d is greater than %d\n", a, b);
    } else {
        printf("%d is not greater than %d\n", a, b);
    }

    // Less than operator
    if (a < b) {
        printf("%d is less than %d\n", a, b);
    } else {
        printf("%d is not less than %d\n", a, b);
    }

    // Greater than or equal to operator
    if (a >= b) {
        printf("%d is greater than or equal to %d\n", a, b);
    } else {
        printf("%d is not greater than or equal to %d\n", a, b);
    }

    // Less than or equal to operator
    if (a <= b) {
        printf("%d is less than or equal to %d\n", a, b);
    } else {
        printf("%d is not less than or equal to %d\n", a, b);
    }

    // Equality operator
    if (a == b) {
        printf("%d is equal to %d\n", a, b);
    } else {
        printf("%d is not equal to %d\n", a, b);
    }

    // Inequality operator
    if (a != b) {
        printf("%d is not equal to %d\n", a, b);
    } else {
        printf("%d is equal to %d\n", a, b);
    }

    return 0;
}

