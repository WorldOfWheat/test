#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug_container(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
int n, m;
vector<int> arr;
vector<int> dp(1e6 + 1);

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (j - arr[i] < 0) continue;            
            dp[j] += dp[j - arr[i]];
            dp[j] %= MOD;
        }
    }
    
    cout << dp[m] << '\n';
}

int main()
{
    fastio;

    solve();

    return 0;
}