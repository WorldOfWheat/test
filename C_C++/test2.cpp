#include <bits/stdc++.h>

using namespace std;

// const int mod = 998244353;
int n, m;
vector<vector<int>> arr;
vector<vector<int>> dp;
vector<vector<bool>> visited;
queue<pair<int, int>> bfs;

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    arr.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= m; j++)
        {
            if (row[j - 1] == '#')
            {
                arr[i][j] = 1;
            }
        }
    }

    dp.resize(n + 1, vector<int>(m + 1, 0));
    visited.resize(n + 1, vector<bool>(m + 1, 0));
    bfs.push({1, 1});
    while (bfs.size())
    {
        pair<int, int> f = bfs.front();
        bfs.pop();
        if (f.first != n && arr[f.first + 1][f.second] != 1)
        {
            if (!visited[f.first + 1][f.second])
            {
                bfs.push({f.first + 1, f.second});
                visited[f.first + 1][f.second] = true;
            }
        }
        if (f.second != m && arr[f.first][f.second + 1] != 1)
        {
            if (!visited[f.first][f.second + 1])
            {
                bfs.push({f.first, f.second + 1});
                visited[f.first][f.second + 1] = true;
            }
        }
        if (arr[f.first - 1][f.second] == 1)
        {
            dp[f.first][f.second] = dp[f.first][f.second - 1] + 1;
            continue;
        }
        if (arr[f.first][f.second - 1] == 1)
        {
            dp[f.first][f.second] = dp[f.first - 1][f.second] + 1;
            continue;
        }
        dp[f.first][f.second] = max(dp[f.first-1][f.second], dp[f.first][f.second-1]) + 1;
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // cout << dp[i][j] << " ";
            result = max(result, dp[i][j]); 
        }
        // cout << "\n";
    }

    cout << result << '\n';

    return 0;
}