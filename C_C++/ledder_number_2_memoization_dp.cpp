#include <bits/stdc++.h>
#define MOD (int) 420

using namespace std;

vector<vector<int>> dp;

int dfs(int start_number, int start_length, int end_length)
{
    if (start_length == end_length) 
    {
        return 1;
    }
    if (dp[start_number][start_length] != 0)
    {
        return dp[start_number][start_length];
    }

    for (int i = 9; i >= start_number; i--)
    {
        dp[start_number][start_length] += dfs(i, start_length - 1, end_length);
        dp[start_number][start_length] %= 420;
    }

    return dp[start_number][start_length];
}

int main()
{
    int n, m;
    string str;
    cin >> n >> m >> str;

    dp.resize(9 + 1, vector<int>(n + 1));

    cout << dfs(str.back() - '0', n, m) << endl;

    return 0;
}
