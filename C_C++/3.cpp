#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

vi arr(10);
int n;
vi dp(1e6 + 1, -1);

int f(int x)
{
    if (x == 0) return 0;
    if (x < 0) return 1e9;
    if (dp[x] != -1) return dp[x];

    int res = 1e9;
    for (int i = 0; i < 10; i++)
    {
        res = min(res, f(x-arr[i]) + 1);
    }
    
    return dp[x] = res;
}

void solve() 
{
    for (int i = 0; i < 10; i++) 
    {
        cin >> arr[i];
    }
    
    cin >> n;
    int ans = f(n);
    if (ans == 1e9) cout << "No Solution\n";
    else cout << ans << '\n';
}

int main() 
{
    fastio;
    solve();
    return 0;
}
