#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define VV vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define INF (int) 1e18

using namespace std;

VV ve;
VV pf;

void solve() {
	
    int n, m;
    cin >> n >> m;

    ve.resize(n, V(m));
    rep (i, 0, n) {
        rep (j, 0, m) {
            cin >> ve[i][j];
        }
    }    

    pf.resize(n+1, V(m+1));
    rep2 (i, 1, n) {
        rep2 (j, 1, m) {
            pf[i][j] = pf[i-1][j] + ve[i-1][j-1];
        }
    }

    int ans = -INF;
    rep2 (i, 0, n) {
        rep2 (j, i+1, n) {
            int sum = 0;   
            rep2 (o, 1, m) {
                sum += pf[j][o] - pf[i][o];
                if (sum < 0) {
                    sum = 0;
                }
                ans = max(ans, sum);
            }
        }
    }

    cout << ans << ln;
    

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
