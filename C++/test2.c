#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void mergeSort(int* arr, int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }

    int middle = (left + right) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle, right);

    int ptrL = left;
    int ptrR = middle;
    int ptr = 0;
    int* result = (int*) malloc((right - left) * 5);
    while (ptrL < middle && ptrR < right)
    {
        while (ptrL < middle && arr[ptrL] < arr[ptrR])
        {
            result[ptr++] = arr[ptrL];
            ptrL++;
        }
        while (ptrR < right && arr[ptrL] >= arr[ptrR])
        {
            result[ptr++] = arr[ptrR];
            ptrR++;
        }
    }
    while (ptrL < middle)
    {
        result[ptr++] = arr[ptrL++];
    }
    while (ptrR < right)
    {
        result[ptr++] = arr[ptrR++];
    }

    for (int i = left; i < right; i++)
    {
        arr[i] = result[i];
    }
}

void quickSort(int* arr, int left, int right)
{
    int middle = (left + right) / 2;
    int ptrL = left;
    int ptrR = right;
    while (ptrL + 1 < ptrR)
    {
        while (arr[ptrL] < arr[middle])
        {
            ptrL++;
        }
        while (arr[ptrR] > arr[middle])
        {
            ptrR--;
        }
        if (ptrL <= ptrR)
        {
            swap(arr + ptrL, arr + ptrR);
            ptrL++;
            ptrR--;
        }
    }
    if (left < ptrR)
    {
        quickSort(arr, left, ptrR);
    }
    if (ptrL < right)
    {
        quickSort(arr, ptrL, right);
    }
}

int main()
{
    int testSize = (int) 2e1;
    int* arr;
    int* _arr;
    arr = (int*) malloc(sizeof(int) * testSize);
    _arr = (int*) malloc(sizeof(int) * testSize);
    FILE* file = fopen("input.txt", "r");
    for (int i = 0; i < testSize; i++)
    {
        fscanf(file, "%i", arr + i);
    }

    for (int i = 0; i < testSize; i++)
    {
        _arr[i] = arr[i];
    }

    mergeSort(arr, 0, testSize);

    for (int i = 0; i < testSize; i++)
    {
        printf("%i ", _arr[i]);
    }

    // double startTime, endTime;
    // /*------------------------------------------------------------------*/
    // startTime = clock();
    // bubbleSort(_arr, 0, testSize);
    // endTime = clock();
    // printf("BubbleSort %lf\n", (endTime - startTime) / CLOCKS_PER_SEC);
    // /*------------------------------------------------------------------*/
    // for (int i = 0; i < testSize; i++)
    // {
    //     *(_arr + i) = *(arr + i);
    // }
    // /*------------------------------------------------------------------*/
    // startTime = clock();
    // quickSort(_arr, 0, testSize);
    // endTime = clock();
    // printf("QuickSort %lf\n", (endTime - startTime) / CLOCKS_PER_SEC);
    // /*------------------------------------------------------------------*/
}
