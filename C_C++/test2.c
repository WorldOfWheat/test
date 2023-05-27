#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int input_size;
    scanf("%i", &input_size);
    bool* input = (bool*) calloc(input_size, sizeof(bool));
    for (int i = 0; i < input_size; i++)
    {
        scanf("%i", input + i);
    }

    int mode; // odd = 1, even = 2
    scanf("%i", &mode);
    bool parity = false;
    for (int i = 0; i < input_size; i++)
    {
        parity ^= *(input + i);
    }

    int output_size = input_size + 1;
    bool* output = (bool*) calloc(output_size, sizeof(bool));
    memcpy(output, input, input_size);

    if (mode == 1)
    {
        *(output + output_size - 1) = !parity;
    }
    if (mode == 2)
    {
        *(output + output_size - 1) = parity;
    }

    

    return 0;
}