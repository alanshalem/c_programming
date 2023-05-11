#include <stdio.h>

int main()
{
    int a = 5;
    int b = 10;

    // Assignment operator
    a = b;
    printf("After assignment: a = %d, b = %d\n", a, b);

    // Increment operator
    a++;
    printf("After post-increment: a = %d\n", a);

    // Decrement operator
    b--;
    printf("After post-decrement: b = %d\n", b);

    // Pre-increment operator
    ++a;
    printf("After pre-increment: a = %d\n", a);

    // Pre-decrement operator
    --b;
    printf("After pre-decrement: b = %d\n", b);

    return 0;
}
