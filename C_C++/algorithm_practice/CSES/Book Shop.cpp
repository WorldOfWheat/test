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
vi dp;

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    
    dp.resize(m + 1);
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = m; j >= arr[i-1].first; j--)
        {
            dp[j] = max(dp[j], dp[j-arr[i-1].first] + arr[i-1].second);
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
