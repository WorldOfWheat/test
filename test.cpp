#include <bits/stdc++.h>
#define int long long
#define VP vector<pii>
#define V vector<int>
#define VV vector<V>
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

int n, m;
V ve(3);
VV dp;

int dfs(int x, int y) {
	if (y > m) {
		return 0;
	}

	if (x == -1) {
		return 1;
	}

	return dfs(x-1, y + ve[0]) + dfs(x-1, y + ve[1]) + dfs(x-1, y + ve[2]);
}

void solve() {

	cin >> n;
	rep (i, 0, 3) {
		cin >> ve[i];
	}
	cin >> m;

	dp.resize(n + 1, V())

	cout << dfs(n - 1, 0) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}