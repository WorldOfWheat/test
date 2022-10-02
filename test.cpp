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

int dfs(int sum, int level) {

	if (sum > m) {
		return 0;
	}

	if (level == n) {
		return 1;
	}

	return (dfs(sum + ve[0], level + 1)) + (dfs(sum + ve[1], level + 1)) + (dfs(sum + ve[2], level + 1));

}

void solve() {

	cin >> n;
	rep (i, 0, 3) {
		cin >> ve[i];
	}
	cin >> m;

	cout << (dfs(0, 0)) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}