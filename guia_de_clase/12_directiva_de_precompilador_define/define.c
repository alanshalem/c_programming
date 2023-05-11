#include <stdio.h>

#define PI 3.14159

int main()
{
    float radius, area;

    printf("Enter the radius of a circle: ");
    scanf("%f", &radius);

    area = PI * radius * radius;

    printf("The area of the circle is: %f\n", area);

    return 0;
}