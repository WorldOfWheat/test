#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n, m;
vp arr;
vector<vi> dp;

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    
    dp.resize(m + 1, vi(n + 1));
    
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (arr[j-1].first > i) 
            {
                dp[i][j] = dp[i][j-1];
                continue;
            }
            dp[i][j] = max(dp[i][j-1], arr[j-1].second + dp[i-arr[j-1].first][j-1]);
        }
    }
    
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }
    
    cout << dp[m][n] << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
