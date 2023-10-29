#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define b2e(x) x.begin(), x.end()
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define INF (int) 1e18

using namespace std;

mt19937 mt;
int n, m;

<<<<<<< HEAD
int qpow(int x, int y, int mod) 
{
    int res = 1;
    while (y > 0) 
    {
        if (y & 1) 
        {
            res *= x;
            res %= mod;
        }
        y >>= 1;
        x *= x;
        x %= mod;
    }
    return res;
=======
int t, n;
vector<ll> table;

void pre() 
{
    table.push_back(9);
    ll now = 89;
    for (int i = 2; i < 18; i++) {
        table.push_back(i * now);
        now *= 10;
        now += 9;
    }
}

void solve()
{
    pre();

    cin >> t;
    while (t--) {
        cin >> n;
        auto it = lower_bound(table.begin(), table.end(), n);
        cout << (it - table.begin()) << '\n';
    }

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}
