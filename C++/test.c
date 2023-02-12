#include <stdio.h>
#include <stdlib.h>

void quickSort(int* arr, int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }

    int* less = (int*) malloc(sizeof(int) * (right - left));
    int* greater = (int*) malloc(sizeof(int) * (right - left));
    int ptrLess = 0;
    int ptrGreater = 0;
    for (int i = left; i < right - 1; i++)
    {
        if (arr[i] < arr[right - 1])
        {
            *(less + ptrLess) = arr[i];
            ptrLess++;
        }
        else
        {
            *(greater + ptrGreater) = arr[i];
            ptrGreater++;
        }
    }

    quickSort(less, 0, ptrLess);
    quickSort(greater, 0, ptrGreater);

    for (int i = 0; i < ptrLess; i++)
    {
        *(arr + i) = *(less + i);
    }
    *(arr + ptrLess) = arr[right - 1];
    for (int i = 0; i < ptrGreater; i++)
    {
        *(arr + i + ptrLess + 1) = *(greater + i);
    }
}

int main()
{
    int n;
    while (scanf("%i", &n) != EOF)
    {
        int* arr;
        arr = (int*) malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%i", arr + i);
        }

        quickSort(arr, 0, n);

        for (int i = 0; i < n; i++)
        {
            printf("%i ", *(arr + i));
        }
        printf("\n");
    }
}