#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int highbit(int n)
{
    unsigned int result = 0;
    while ((1 << result) < n)
    {
        result++;
    }
    return result;
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
    int input_pointer = input_size - 1;
    for (int i = output_size - 1; i >= 0; i--)
    {
        int bit_index = output_size - i;
        if (!(bit_index & bit_index - 1))
        {
            continue;
        }
        *(output + i) = *(input + input_pointer--);
    }

    bool* hamming_code = (bool*) calloc(hamming_code_size, sizeof(bool));
    for (int i = 0; i < output_size; i++)
    {
        if (*(output + i))
        {
            for (int j = 0; j < hamming_code_size; j++)
            {
                *(hamming_code + j) ^= (bool) ((output_size - i) & (1 << (hamming_code_size - j - 1)));
            }
        }
    }

    int hamming_code_pointer = hamming_code_size - 1;
    for (int i = output_size - 1; i >= 0; i--)
    {
        int bit_index = output_size - i;
        if ((bit_index & bit_index - 1))
        {
            continue;
        }
        *(output + i) = *(hamming_code + hamming_code_pointer--);
    }

    for (int i = 0; i < output_size; i++)
    {
        printf("%i ", *(output + i));
    }
    printf("\n");

    return 0;
}