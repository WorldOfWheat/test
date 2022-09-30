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
	dp.resize(n+1, VV(2, V(m+1)));

	rep (i, 0, n) {
		cin >> ve[i];
	}

	rep2 (i, 1, n) {
		rep2 (j, 1, m) {
			int top = ve[i-1];

			dp[i][0][m] = max(dp[i-1][0][m], dp[i-1][1][m-1] + top);
			dp[i][1][m] = max(dp[i-1][1][m], dp[i-1][0][m-1] - top);
		}
	}

	cout << (dp[n][0][m]) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}