#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int* merge(int* arr1, int* arr2, int left1, int right1, int left2, int right2)
{
    int* result;
    int size = max(right1 - left1, right2 - left2);
    result = (int*) malloc(sizeof(int) * size * 2);
    int ptrL = left1;
    int ptrR = left2;
    int ptrResult = 0;
    while (1)
    {
        if (ptrL >= right1 || ptrR >= right2)
        {
            break;
        }

        if (arr1[ptrL] > arr2[ptrR])
        {
            *(result + ptrResult) = arr2[ptrR];
            ptrR++;
        }
        else
        {
            *(result + ptrResult) = arr1[ptrL];
            ptrL++;
        }
        ptrResult++;           
    }
    while (ptrL < right1)
    {
        *(result + ptrResult) = arr1[ptrL];
        ptrL++;
        ptrResult++;
    }
    while (ptrR < right2)
    {
        *(result + ptrResult) = arr2[ptrR];
        ptrR++;
        ptrResult++;
    }

    return result;
}

int* mergeSort(int* arr, int left, int right)
{
    if (left + 1 >= right)
    {
        return arr + left;
    }

    int mid = (right + left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    int* result = merge(arr, arr, left, mid, mid, right);
    for (int i = left; i < right; i++)
    {
        printf("%i ", i);
        arr[i] = *(result + i - left);
    }
    printf("\n");
}

int main()
{
    srand(time(0));

    int testSize = 50000;
    int* arr;
    arr = (int*) malloc(sizeof(int) * testSize);
    for (int i = 0; i < testSize; i++)
    {
        *(arr + i) = (rand() + 100) % 200;
    }

    mergeSort(arr, 0, testSize);
}