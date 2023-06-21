#include <bits/stdc++.h>
#define MOD (int) 420

using namespace std;

int main()
{
    int n = 1, m = 1e6;
    string str = "1";
    vector<vector<int>> dp;
    dp.resize(10, vector<int>(m + 1));
    dp[str.back() - '0'][n] = 1;
    for (int i = str.back() - '0'; i <= 9; i++)
    {
        for (int j = n + 1; j <= m; j++)
        {
            dp[i][j] += dp[i][j - 1] + dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }

    int sum = 0;
    for (int i = 1; i <= 9 ; i++)
    {
        sum += dp[i][m];
        sum %= MOD;
    }
    cout << sum << endl;

    return 0;
}
