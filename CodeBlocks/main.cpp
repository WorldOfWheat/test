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

<<<<<<< HEAD:test.cpp
int n;
V weight;
VV graph;
V dp;

void dfs(int parent, int now) {

	dp[now] = weight[now];

	for (auto i : graph[now]) {
		if (i == parent) {
			continue;
		}

		dfs(now, i);
		dp[now] = max(dp[now], dp[now] + dp[i]);
	}

}

void solve() {

	cin >> n;
	
	weight.resize(n + 1);
	graph.resize(n + 1);
	dp.resize(n + 1);

	rep2 (i, 1, n) {
		cin >> weight[i];
	}
	rep2 (i, 1, n - 1) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(-1, 1);

	cout << (dp[1]) << ln;
=======


void solve() {


>>>>>>> 2d8fa7a0c9a02c4658c0e248315472be9aa354d2:CodeBlocks/main.cpp

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
