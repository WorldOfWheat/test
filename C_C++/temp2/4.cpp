#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;

int n, m, k;
vvi arr;
vector<vvi> dp;

void solve() 
{
    cin >> n >> m >> k;

    arr.resize(n, vi(m+1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    dp.resize(k+1, vvi(n+1, vi(m+1)));
    dp[0][0][0] = 1e18;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j][0] = 1e18;
        }
        for (int j = 1; j <= m; j++)
        {
            dp[i][0][j] = 1e18;
        }
        dp[i][1][1] = arr[0][0];
    }

    for (int i = 0; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int l = 1; l <= m; l++)
            {
                if (j == 1 && l == 1) continue;
                if (i == 0) 
                {
                    dp[i][j][l] = min(dp[i][j-1][l], dp[i][j][l-1]) + arr[j-1][l-1];
                    continue;
                }

                dp[i][j][l] = min({dp[i][j-1][l], dp[i][j][l-1], dp[i-1][j-1][l-1]}) + arr[j-1][l-1];
            }
        }
    }

    /// for (int j = 1; j <= n; j++)
    /// {
    ///     for (int l = 1; l <= m; l++)
    ///     {
    ///         cerr << dp[0][j][l] << ' ';
    ///     }
    ///     cerr << '\n';
    /// }
    
    cout << (dp[k][n][m]) << '\n';
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
