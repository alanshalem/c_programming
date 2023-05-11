#include <stdio.h>

int main(void){
    int arr[4]={2500,3500,4500,5500};
    int *ptr1, *ptr2;
    ptr1 = arr;
    ptr2 = &arr[2];

    printf ("%ld \n", (ptr2 - ptr1));
    printf ("%ld \n", ((long) ptr2 - (long) ptr1));
    printf ("%d \n", (*ptr2 - *ptr1));
    printf ("%p \n", ptr2);
    printf ("%x \n", *ptr2);
    printf ("%p \n", ptr2++);
    printf ("%x \n", *(ptr2++));
    printf ("%p \n", ptr2);

    return 0;
}
