#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n, m;
vector<vi> dp(500+1, vi(500+1));

int f(int x, int y)
{
    if (x == y) 
    {
        return 0;
    }
    
    if (dp[x][y] != 0) return dp[x][y];
    
    int res = 1e9;
    for (int i = 1; i <= (x >> 1); i++) 
    {
        res = min(res, f(i, y) + f(x-i, y) + 1);
    }
    for (int i = 1; i <= (y >> 1); i++) 
    {
        res = min(res, f(x, i) + f(x, y-i) + 1);
    }

    return dp[x][y]=res;
}

void solve() 
{
    cin >> n >> m;
    cout << f(n, m) << '\n';
}

int main() 
{
    fastio;
    solve();
    return 0;
}
