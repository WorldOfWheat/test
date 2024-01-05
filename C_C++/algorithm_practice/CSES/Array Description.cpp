#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug_container(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

const int MOD = 1e9 + 7;
int n, m;
vi arr;
vi zero_indexes;
vector<vi> dp;

void solve() 
{
    cin >> n >> m;
    
    arr.resize(n);
    int last_zero_index = -1;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    
    dp.resize(n+1, vi(m+2, 0));
    if (arr.front() == 0) 
    {
        fill(dp[0].begin(), dp[0].end(), 1);
        dp[0][0] = 0;
        dp[0][m+1] = 0;
    }
    else dp[0][arr.front()] = 1;

    for (int i = 1; i < n; i++) 
    {
        if (arr[i] == 0) 
        {
            for (int j = 1; j <= m; j++) 
            {
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
            }
        }
        else 
        {
            dp[i][arr[i]] += dp[i-1][arr[i]-1];
            dp[i][arr[i]] %= MOD;
            dp[i][arr[i]] += dp[i-1][arr[i]+1];
            dp[i][arr[i]] %= MOD;
            dp[i][arr[i]] += dp[i-1][arr[i]];
            dp[i][arr[i]] %= MOD;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i++) 
    {
        ans += dp[n-1][i];
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main()
{
    fastio;

    solve();

    return 0;
}