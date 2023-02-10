#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
    while (true)
    {
        int firstNum;
        scanf("%d", &firstNum);
        if (firstNum == 0)
        {
            break;
        }
        int* arr;
        arr = (int*) malloc(sizeof(n)*sizeof(int));
        *arr = firstNum;
        for (int i = 1; i < n; i++)
        {
            scanf("%d", (arr + i));
        }

        int* stack;
        stack = (int*) malloc(sizeof(n)*sizeof(int));
        int tail = 0;
        int now = 0;
        for (int i = 1; i <= n; i++)
        {
            *(stack + tail) = i;
            tail++;
            while (tail >0 && *(arr + now) == )
        }
    }

    return 0;
}