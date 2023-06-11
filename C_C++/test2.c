#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int n = 0;
    while (!(10 * n - 4112 == 13296 - 7 * n))
    {
        n++;
    }
    printf("%d\n", n);

    // int n = 1;
    // while (!(n % 27 == 3 && n % 37 == 4 && n % 41 == 5))
    // {
    //     n++;
    // }
    // printf("%d\n", n);

    return 0;
}