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
        arr = (int*) malloc(sizeof(n - 1)/sizeof(int));
        *arr = firstNum;
        for (int i = 1; i < n; i++)
        {
            scanf("%d", (arr + i));
        }
    }

    return 0;
}