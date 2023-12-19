#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    a = 1;
    b = 1;
    printf("%i %i ", a, b);
    for (int i = 2; i < 10; i++) 
    {
        c = a + b;
        printf("%i ", c);
        a = b;
        b = c;
    }

    return 0;
}