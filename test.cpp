#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
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

int n;
VV graph;
V vis;

void dfs(int parent, int now) {

	for (auto i : graph[now]) {
		if (i == parent) {
			continue;
		}

		dfs(now, i);
	}

	if (vis[now] == 0) {
		vis[parent] = 1;
	}

}

void solve() {

	cin >> n;

	graph.resize(n+1);
	vis.resize(n+1);

	rep (i, 1, n) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(0, 1);

	int ans = 0;
	rep2 (i, 2, n) {
		ans += vis[i];
	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}