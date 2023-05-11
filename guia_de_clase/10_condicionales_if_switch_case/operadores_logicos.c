int main()
{
    int a = 5, b = 10, c = 15;

    // AND operator
    if (a < b && b < c)
    {
        printf("Both conditions are true\n");
    }
    else
    {
        printf("At least one condition is false\n");
    }

    // OR operator
    if (a < b || b > c)
    {
        printf("At least one condition is true\n");
    }
    else
    {
        printf("Both conditions are false\n");
    }

    // NOT operator
    if (!(a == b))
    {
        printf("%d is not equal to %d\n", a, b);
    }
    else
    {
        printf("%d is equal to %d\n", a, b);
    }

    return 0;
}
