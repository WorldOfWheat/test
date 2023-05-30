#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void printBoolArray(bool* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", *(array + i));
    }
    printf("\n");
}

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
    int input_pointer = 0;
    for (int i = 0; i < output_size; i++)
    {
        if (!(i & i + 1))
        {
            continue;
        }
        *(output + i) = *(input + input_pointer++);
    }

    bool* hamming_code = (bool*) calloc(hamming_code_size, sizeof(bool));
    for (int i = 0; i < output_size; i++)
    {
        if (*(output + i))
        {
            for (int j = 0; j < hamming_code_size; j++)
            {
                *(hamming_code + j) ^= (bool) ((i + 1) & (1 << (hamming_code_size - j - 1)));
            }
        }
    }

    int hamming_code_pointer = hamming_code_size - 1;
    for (int i = 0; i < output_size; i++)
    {
        if ((i & i + 1))
        {
            continue;
        }
        *(output + i) = *(hamming_code + hamming_code_pointer--);
    }

    printBoolArray(hamming_code, hamming_code_size);
    printBoolArray(output, output_size);

    *(output + 5) = !*(output + 5);

    memset(hamming_code, 0, hamming_code_size);
    for (int i = 0; i < output_size; i++)
    {
        if (*(output + i))
        {
            for (int j = 0; j < hamming_code_size; j++)
            {
                *(hamming_code + j) ^= (bool) ((i + 1) & (1 << (hamming_code_size - j - 1)));
            }
        }
    }

    printBoolArray(hamming_code, hamming_code_size);
    printBoolArray(output, output_size);

    return 0;
}