//C program to swap 2 integers that are given by user
#include <stdio.h>

void swap(int a, int  b);
int main()
{
        //intializing a and b
        int a, b;

        //asking for 2 integers from the user
        printf("Write 2 integers to swap\n");
        scanf("%d%d", &a, &b);

        //printing integers before the swap
        printf("\nBefore Swap : a = %d, b = %d", a , b);
        swap(a, b);

}


void swap(int a, int b)
{
        int first_a = a;
        a = b;
        b = first_a;
        //printing integers after the swap
        printf("\nAfter Swap : a = %d, b = %d\n", a, b);

}

