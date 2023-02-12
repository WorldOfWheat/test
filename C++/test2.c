#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int* numA, int* numB)
{
    int ptrTemp = *numA;
    *numA = *numB;
    *numB = ptrTemp;
}

void bubbleSort(int* arr, int left, int right)
{
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = left; i < right - 1; i++)
        {
            if (*(arr + i) > *(arr + i + 1))
            {
                swap(arr + i, arr + i + 1);
                flag = 1;
            }
        }
    }
}

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
    int testSize = (int) 1e6;
    int* arr;
    arr = (int*) malloc(sizeof(int) * testSize);
    FILE* file = fopen("input.txt", "r");
    for (int i = 0; i < testSize; i++)
    {
        fscanf(file, "%i", arr + i);
    }

    double startTime = clock();
    bubbleSort(arr, 0, testSize);
    double endTime = clock();
    printf("%lf\n", (endTime - startTime) / CLOCKS_PER_SEC);
}
