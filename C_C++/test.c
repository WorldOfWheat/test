#include <stdio.h>
#include <stdlib.h>

int main()
{
    int** arr = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * 4);
    }

    return 0;
}