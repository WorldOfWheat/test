#include <stdio.h>

void swap(int* numA, int* numB)
{
    int ptrTemp = *numA;
    *numA = *numB;
    *numB = ptrTemp;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    swap(&arr[4], &arr[1]);
    for (int i = 0; i < 5; i++)
    {
        printf("%i ", arr[i]);
    }

    return 0;
}