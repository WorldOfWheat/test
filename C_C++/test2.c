#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct House {
    char buf[18];
    int p1;
    int p2;
    int p3;
    int p4;

} house;

int main()
{
    while (1)
    {
        house.p1 = 0;
        house.p2 = 0;
        house.p3 = 0;
        house.p4 = 0;
        scanf("%s", house.buf);
        printf("%s\n", house.buf);
        printf("%i\n", house.p1);
        printf("%i\n", house.p2);
        printf("%i\n", house.p3);
        printf("%i\n", house.p4);
    }

    return 0;
}