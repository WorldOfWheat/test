#include <bits/stdc++.h>
#define int long long
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
VV graph;
V vis;

bool dfs(int x, int color) {

	for (auto i : graph[x]) {
		if (vis[i] == color) {
			return false;
		}	
		if (vis[i]) {
			continue;
		}
		vis[i] = 3 ^ color;

		if (!dfs(i, 3 ^ color)) {
			return false;
		}
	}

	return true;

}

void solve() {

	graph.clear();
	vis.clear();

	cin >> n >> m;

	graph.resize(n);
	vis.resize(n);

	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	rep (i, 0, n) {
		if (vis[i]) {
			continue;
		}
		vis[i] = 1;

		if (!dfs(i, 1)) {
			cout << "no" << ln;
			return;
		}
	}

	cout << "yes" << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) solve();

	return 0;
	
}