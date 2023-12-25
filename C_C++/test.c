#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%i", &n);
    printf("%i", n / 12 * 50 + n % 12 * 5);

    return 0;
}