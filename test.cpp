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
VV dp;

int dfs(int l, int r) { 

	if (dp[l][r] >= 0) {
		return dp[l][r];
	}

	int res = INF;

	rep (i, l+1, r) {
		res = min(1ll * dfs(i, r) + dfs(l, i), res);
	}

	res += ve[r] - ve[l];

	return (dp[l][r] = res);

}

void solve() {

	int n, m;

	cin >> n >> m;

	ve.resize(n+2);
	dp.resize(n+2, V(n+2, -1));

	ve[0] = 0;
	ve[n+1] = m;

	rep2 (i, 1, n) {
		cin >> ve[i];
	}

	rep (i, 0, n+1) {
		dp[i][i+1] = 0;
	}

	cout << (dfs(0, n+1)) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}