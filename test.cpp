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
int start, goal;
vector<vector<pii>> graph;
V dp;
V dp2;
V indeg;

void bfs() {

	queue<int> qu;

	rep (i, 0, n) {
		if (indeg[i] == 0) {
			qu.push(i);
		}
	}

	while (qu.size()) {
		int top = qu.front();
		qu.pop();

		for (auto i : graph[top]) {
			int f = i.F;
			int s = i.S;

			if (dp[top] < INF) {
				dp[f] = min(dp[f], dp[top] + s);
				dp2[f] = max(dp2[f], dp2[top] + s);
			}

			indeg[f]--;
			if (indeg[f] == 0) {
				qu.push(f);
			}
		}
	}

	if (dp[goal] == INF) {
		cout << "No path" << ln << "No path" << ln;
	}
	else {
		cout << dp[goal] << ln << dp2[goal] << ln;
	}

}

void solve() {

	cin >> n >> m >> start >> goal;

	graph.resize(n);
	indeg.resize(n);
	dp.resize(n, INF);
	dp2.resize(n, -INF);
	dp[start] = 0;
	dp2[start] = 0;

	rep (i, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({b, c});
		indeg[b]++;
	}

	bfs();

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}