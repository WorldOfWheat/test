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
V ve;
VVP graph;
V cnt;
V dp;

void dfs(int parent, int now) {

	cnt[now] = 1;

	for (auto i : graph[now]) {
		int f = i.F;
		int s = i.S;

		if (f == parent) {
			continue;
		}
		
		dfs(now, f);

		cnt[now] += cnt[f];
		dp[now] += (dp[f] + cnt[f] * (n - cnt[f]) * s);
	}
}

void solve() {

	cin >> n;

	ve.resize(n+1);
	graph.resize(n+1);
	cnt.resize(n+1);
	dp.resize(n+1);

	rep (i, 2, 5) {
		cin >> ve[i];
	}

	rep (i, 2, 5) {
		int a;
		cin >> a;
		graph[ve[i]].push_back({i, a});
		graph[i].push_back({ve[i], a});
	}

	dfs(0, 1);

	rep2 (i, 1, n) {
		cerr << dp[i] << ln;
	}

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}
