#include <stdio.h>
#include <stdlib.h>


int main()
{
    int dp[10];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < 10; i++) dp[i] = dp[i-1] + dp[i-2];
    for (int i = 0; i < 10; i++) printf("%i ", dp[i]);

    return 0;
}