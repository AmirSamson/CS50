#include <cs50.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int a = 50;
    int b = 10;

    printf("a is %i, and b is %i\n", a, b);
    swap(&a, &b);
    printf("a is %i, and b is %i\n", a,b);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
