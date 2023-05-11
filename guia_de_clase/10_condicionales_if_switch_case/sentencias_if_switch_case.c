#include <stdio.h>

int main()
{
    int num = 3;

    // If statement
    if (num == 1)
    {
        printf("The number is one.\n");
    }
    else if (num == 2)
    {
        printf("The number is two.\n");
    }
    else
    {
        printf("The number is not one or two.\n");
    }

    // Switch-case statement
    switch (num)
    {
    case 1:
        printf("The number is one.\n");
        break;
    case 2:
        printf("The number is two.\n");
        break;
    default:
        printf("The number is not one or two.\n");
        break;
    }

    return 0;
}
