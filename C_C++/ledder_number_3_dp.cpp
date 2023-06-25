#include <bits/stdc++.h>
#define MOD (int) 420

using namespace std;

int main()
{
    int n = 5, m = 2;
    string str = "11";
    vector<vector<int>> dp;
    dp.resize(10, vector<int>(n + 1));
    dp[str.back() - '0'][m] = 1;
    for (int i = str.back() - '0'; i <= 9; i++)
    {
        for (int j = m + 1; j <= n; j++)
        {
            dp[i][j] += dp[i][j - 1] + dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }

    for (int i = 9; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    int sum = 0;
    for (int i = 1; i <= 9 ; i++)
    {
        sum += dp[i][n];
        sum %= MOD;
    }
    cout << sum << endl;

    return 0;
}
