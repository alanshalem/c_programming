#include <stdio.h>

// Function declarations
int sum(int x, int y);
void print_hello();

int main()
{
    int a = 5, b = 7;
    int result = sum(a, b);
    printf("The sum of %d and %d is %d\n", a, b, result);
    print_hello();
    return 0;
}

// Function definitions
int sum(int x, int y)
{
    return x + y;
}

void print_hello()
{
    printf("Hello, world!\n");
}
