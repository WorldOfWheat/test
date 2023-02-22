#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* numA, int* numB)
{
    int ptrTemp = *numA;
    *numA = *numB;
    *numB = ptrTemp;
}

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
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

int* merge(int* arr, int left1, int right1, int* arr2, int left2, int right2)
{
    int result_size = max(right1 - left1, right2 - left2) * 2;
    int* result = (int*) malloc(sizeof(int) * result_size);
    int ptr = 0;
    int ptrL = left1;
    int ptrR = left2; 
    while (ptrL < right1 && ptrR < right2)
    {
        while (ptrL < right1 && arr[ptrL] < arr2[ptrR])
        {
            result[ptr++] = arr[ptrL++];
        }
        while (ptrR < right2 && arr2[ptrR] <= arr[ptrL])
        {
            result[ptr++] = arr2[ptrR];
            ptrR++;
        }
    }
    while (ptrL < right1)
    {
        result[ptr++] = arr[ptrL++];
    }
    while (ptrR < right2)
    {
        result[ptr++] = arr2[ptrR++];
    }

    return result;
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

    int* result = (int*) merge(arr, left, middle, arr, middle, right);
    for (int i = left; i < right; i++)
    {
        arr[i] = result[i - left];
    }
}

void quickSort(int* arr, int left, int right)
{
    int middle = arr[(left + right) / 2];   
    int ptrL = left;
    int ptrR = right - 1;
    // printf("%i\n", arr[middle]);
    while (ptrL <= ptrR)
    {
        // printf("%i %i\n", ptrL, ptrR);
        while (arr[ptrL] < middle)
        {
            ptrL++;
        }
        while (arr[ptrR] > middle)
        {
            ptrR--;
        }
        if (ptrL <= ptrR)
        {
            swap(&arr[ptrL], &arr[ptrR]);
            ptrL++;
            ptrR--;
        }
    }
    printf("%i %i %i %i\n", left, ptrL, ptrR, right);
    if (left < ptrR)
        quickSort(arr, left, ptrR);
    if (ptrL < right)
        quickSort(arr, ptrL, right);
}

int main()
{
    int testSize = (int) 2e1;
    int* arr = (int*) malloc(sizeof(int) * testSize);
    int* _arr = (int*) malloc(sizeof(int) * testSize);
    FILE* file = fopen("input.txt", "r");
    for (int i = 0; i < testSize; i++)
    {
        fscanf(file, "%i", &arr[i]);
    }

    double startTime, endTime;
    // /*------------------------------------------------------------------*/
    // for (int i = 0; i < testSize; i++)
    // {
    //     _arr[i] = arr[i];
    // }
    // startTime = clock();
    // bubbleSort(_arr, 0, testSize);
    // endTime = clock();
    // printf("BubbleSort %lf\n", (endTime - startTime) / CLOCKS_PER_SEC);
    // /*------------------------------------------------------------------*/
    for (int i = 0; i < testSize; i++)
    {
        _arr[i] = arr[i];
        printf("%i ", _arr[i]);
    }
    printf("\n");
    startTime = clock();
    quickSort(_arr, 0, testSize - 1);
    endTime = clock();
    printf("QuickSort %lf\n", (endTime - startTime) / CLOCKS_PER_SEC);
    /*------------------------------------------------------------------*/
    for (int i = 0; i < testSize; i++)
    {
        printf("%i ", _arr[i]);
    }
}
