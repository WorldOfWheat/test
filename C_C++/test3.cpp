#include <bits/stdc++.h>

using namespace std;

int n, m;
int k;
vector<pair<int, int>> wolf;
vector<vector<int>> dp;

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        wolf.clear();
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        cin >> k;
        wolf.resize(k);
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            wolf.push_back({x, y});
        }
        sort(wolf.begin(), wolf.end());

        dp.resize(n + 1, vector<int>(m + 1));
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if ((i == 0 && j == 0) || binary_search(wolf.begin(), wolf.end(), make_pair(i, j)))
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1];
                    continue;
                }
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "#" << dp[n][m] << '\n';
    }

    return 0;
}