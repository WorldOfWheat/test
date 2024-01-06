#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n;
vi arr;
vector<vi> dp(5000+1, vi(5000+1, -1));

int f(int l, int r, int depth)
{
    if (l + 1 > r) return arr[l];
    if (dp[l][r] != -1) return dp[l][r];

    if (depth & 1)
    {
        return dp[l][r] = max(f(l+1, r, depth ^ 1), f(l, r-1, depth ^1));
    }
    else 
    {
        return dp[l][r] = max(f(l+1, r, depth ^ 1) + arr[l], f(l, r-1, depth ^ 1) + arr[r]);
    }
}

void solve() 
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << f(0, n-1, 1) << '\n';
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cerr << dp[i][j] << ' ';
        }
        cerr << '\n';
    }
}

int main() 
{
    fastio;
    solve();
    return 0;
}
