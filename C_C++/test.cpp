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
}

bool is_prime(int x) {
    if (x <= 2) {
        return x == 2;
    }
    for (int i = 0; i < 10; i++) {
        int k = (mt() % ((x - 1) - 2 + 1) + 2);
        if (qpow(k, x - 1, x) != 1) {
            return false;
        }
    }
    return true;
}

void solve() 
{
    while (cin >> n >> m) {
        int ans = 0;
        for (int i = n; i <= m; i++) 
        {
            if (is_prime(i)) 
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}
