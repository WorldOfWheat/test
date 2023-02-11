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
        printf("%d %d\n", arr1[ptrL], arr2[ptrR]);
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

void mergeSort(int* arr, int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }

    int mid = (right + left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, arr, left, mid, mid, right);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    &arr = merge(arr, arr, 0, 5, 5, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(arr + i));
    }

    // srand(time(0));

    // int arr[10] = {0};
    // for (int i = 0; i < 10; i++)
    // {
    //     *(arr + i) = (rand() + 100) % 100;
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d ", *(arr + i));
    // }
    // printf("\n");

    // printf("%p\n", arr);
    // mergeSort(arr, 0, 10);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d ", *(arr + i));
    // }
}