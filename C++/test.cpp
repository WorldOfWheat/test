#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

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

int main()
{
    int size = 50;
    int* arr = (int*) malloc(sizeof(int) * size);
    int* arr2 = (int*) malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 2;
    }
    for (int i = 0; i < size; i++)
    {
        arr2[i] = i * 2 + 1;
    }
    int* result = merge(arr, 0, 25, arr2, 0, 25);
    for (int i = 0; i < size; i++)
    {
        printf("%i ", result[i]);
    }

    return 0;
}