#include <bits/stdc++.h>
#define MOD (int) 420

using namespace std;

vector<vector<int>> dp;

int dfs(int start_number, int length_now, int total_length)
{
    if (length_now == total_length) 
    {
        return 1;
    }

    for (int i = start_number; i <= 9; i++)
    {
        dp[length_now][start_number] += dfs(i, length_now + 1, total_length);
        dp[length_now][start_number] %= MOD;
    }

    return dp[length_now][start_number];
}

int main()
{
    int n = 5, m = 1;
    string str = "1";
    dp.resize(n + 1, vector<int>(9 + 1));

    cout << dfs(str.back() - '0', m, n) << endl;

    return 0;
}
