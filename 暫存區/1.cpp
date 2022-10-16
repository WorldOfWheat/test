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

V ve;
vector<VV> dp;

void solve() {

	int n, m;

	cin >> n >> m;

	ve.resize(n);
	dp.resize(2, VV(2, V(m+1)));

	rep (i, 0, n) {
		cin >> ve[i];
	}

	rep2 (i, 0, m) {
		dp[0][1][i] = -INF;
	}

	int sw = 0;
	int sw2 = 1;

	rep2 (i, 1, n) {
		int top = ve[i-1];

		rep (j, 0, m) {
			dp[sw2][1][j] = max(dp[sw][0][j] - top, dp[sw][1][j]);
		}

		rep2 (j, 1, m) {
			dp[sw2][0][j] = max(dp[sw][1][j-1] + top, dp[sw][0][j]);
		}

		sw = 1 - sw;
		sw2 = 1 - sw2;
	}

	cout << (*max_element(dp[sw][0].begin(), dp[sw][0].end())) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}