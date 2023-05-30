#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    while (true)
    {
        long long n;
        scanf("%ll", &n);
        long long hamming_code_size = 0;
        while (((1 << hamming_code_size) - hamming_code_size - 1) < n)
        {
            hamming_code_size++;
        }
        printf("%i\n", hamming_code_size);

        long long x = 0;
        while (((1 << x) - 1 < hamming_code_size + n))
        {
            x++;
        }
        printf("%i\n", x);
    }

    return 0;
}