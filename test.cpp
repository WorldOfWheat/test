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

int n, m;
VV graph;
V weight;
V dp;
V dp2;

void dfs(int parent, int now) {

	dp[now] = weight[now];

	for (auto i : graph[now]) {
		if (i == parent) {
			continue;
		}

		dfs(now, i);
		dp[now] += dp2[i];
		dp2[now] += max(dp[i], dp2[i]);
	}

}

void solve() {

	cin >> n >> m;

	graph.resize(n + 1);
	weight.resize(n + 1);
	dp.resize(n + 1);
	dp2.resize(n + 1);

	weight[1] = m;
	rep2 (i, 2, n) {
		int a, b;
		cin >> a >> b;

		graph[i].push_back(a);
		graph[a].push_back(i);
		weight[i] = b;
	}

	dfs(-1, 1);

	cout << (max(dp[1], dp2[1])) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}