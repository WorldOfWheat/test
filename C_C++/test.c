#include <stdio.h>
#include <stdlib.h>

void solve(int n, int u, int d)
{
    if (u - d <= 0) 
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    
    printf("%i\n", (n-u) / (u - d) + 1);
}

void solve2(int n, int u, int d)
{
    if (u - d <= 0) 
    {
        printf("IMPOSSIBLE\n");
        return;
    }

    int sum = 0;    
    for (int i = 0; sum < n; i++)
    {
        sum = sum + u;
        if (sum >= n)
        {
            printf("%i", i + 1);
            return;
        }
        sum = sum - d;
    }
    // int count = 0;
    // while (sum < n)
    // {
    //     count++;
    //     sum += u;
    //     if (sum >= n)
    //     {
    //         printf("你好，%i", count);
    //         return;
    //     }
    //     sum -= d;
    // }
    printf("\n");
}

int main()
{
    int n, u, d;
    scanf("%i %i %i", &n, &u, &d);
    printf("Solve1:\n");
    solve(n,u,d);
    printf("Solve2:\n");
    solve2(n,u,d);

    return 0;
}