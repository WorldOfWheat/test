#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int input_size;
    scanf("%i", &input_size);

    bool* input = (bool*) calloc(input_size, sizeof(bool));
    for (int i = 0; i < input_size; i++)
    {
        int temp;
        scanf("%i", &temp);
        *(input + i) = temp == true;
    }

    int hamming_code_size = 0;
    while (((1 << hamming_code_size) - hamming_code_size - 1) < input_size)
    {
        hamming_code_size++;
    }

    int output_size = input_size + hamming_code_size;
    bool* output = (bool*) calloc(output_size, sizeof(bool));
    int start_pointer_input = 0;
    for (int i = 0; i < output_size; i++)
    {
        if (i & (i - 1))
        {
            printf("%i ", *(output+i));
            continue;
        }
        *(output + i) = *(input + start_pointer_input++);
        printf("%i ", *(output+i));
    }

    return 0;
}