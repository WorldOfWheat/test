#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

const int MOD = 1e9 + 7;
const int MOD_INVERSE = 5e8 + 4;
int n;
vp arr;
v2i dp;

void solve()
{
    cin >> n;
    
    int total_sum = (1 + n) * n / 2;

    if (total_sum & 1) 
    {
        cout << 0 << '\n';
        return;
    }
    
    dp.resize(n + 1, vi(total_sum / 2 + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= total_sum / 2; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (i > j) continue;
            dp[i][j] += dp[i-1][j-i];
            dp[i][j] %= MOD;
        }
    }
    
    cout << dp[n][total_sum / 2] * MOD_INVERSE % MOD << '\n';
}

signed main()
{
    fastio;
    solve();
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

const int MOD = 1e9 + 7;
const int MOD_INVERSE = 5e8 + 4;
int n;
vp arr;
vi dp;

void solve()
{
    cin >> n;
    
    int total_sum = (1 + n) * n / 2;

    if (total_sum & 1) 
    {
        cout << 0 << '\n';
        return;
    }
    
    dp.resize(total_sum / 2 + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = total_sum / 2; j >= i; j--)
        {
            dp[j] += dp[j-i];
            dp[j] %= MOD;
        }
    }
    
    cout << dp[total_sum / 2] * MOD_INVERSE % MOD << '\n';
}

signed main()
{
    fastio;
    solve();
    return 0;
}