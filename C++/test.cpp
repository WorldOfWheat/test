#include <bits/stdc++.h>

using namespace std;

int t;
int n;
vector<vector<int>> dp;

void solve() 
{
    cin >> t;
    while (t--)
    {
        dp.clear();

        cin >> n;
        dp.resize(n, vector<int>(2));

        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
            dp[i][0] %= ((int) 1e9 + 7);
            dp[i][1] %= ((int) 1e9 + 7);
        }

        cout << ((dp[n - 1][0] + dp[n - 1][1]) % ((int) 1e9 + 7)) << '\n';
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}