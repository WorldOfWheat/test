<<<<<<< HEAD
#include <bits\stdc++.h>

using namespace std;

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
=======
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
>>>>>>> 0508370433be0f9b5b8f2d483d6e9e0d4167c340

    return 0;
}