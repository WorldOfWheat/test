#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n;
vi arr(10);
vi dp;

void solve()
{
    for (int i = 0; i < 10; i++) cin >> arr[i];
    cin >> n;
    
    dp.resize(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int current_sum = i;
        for (int j = 0; j < 10; j++)
        {
            if (current_sum - arr[j] < 0) continue;
            dp[i] = min(dp[i], dp[current_sum - arr[j]] + 1);
        }
    }
    
    if (dp[n] == 1e9) cout << "No Solution\n" ;
    else cout << dp[n] << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
