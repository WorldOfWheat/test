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

VV ve, dp;

void solve() {

	int n, m;
	cin >> n >> m;

	ve.resize(n, V(m));
	dp.resize(n + 1, V(m + 1));

	rep (i, 0, n) {
		rep (j, 0, m) {
			cin >> ve[i][j];
		}
	}

	rep2 (i, 0, n) {
		dp[i][0] = -INF;
	}
	rep2 (i, 0, m) {
		dp[0][i] = -INF;
	}

	rep2 (i, 1, n) {
		rep2 (j, 1, m) {
			if (i == 1 && j == 1) {
				dp[i][j] = ve[i-1][j-1];
				continue;
			}
			dp[i][j] = ve[i-1][j-1] + max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << (dp[n][m]) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}