#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // solution 1
    for (int i = 1; i <= 100; i += 2) printf("%i ", i);
    printf("\n");
    // solution 2
    int counter = 1;
    while (counter <= 100) 
    {
        printf("%i ", counter);
        counter += 2;
    }
    printf("\n");
    // solution 3
    counter = 1;
    do
    {
        printf("%i ", counter);
        counter += 2;
    } while (counter <= 100);
    printf("\n");
}