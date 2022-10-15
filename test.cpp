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

V ve;
int n;
VVP graph;
V res;

void dfs(int parent, int now, int sum) {

	//cerr << parent << sp << now << ln;

	for (auto i : graph[now]) {
		if (i.F == parent) {
			continue;
		}

		dfs(now, i.F, sum + i.S);

	}

	res[now] += sum;

}

void solve() {

	cin >> n;

	ve.resize(n+1);
	graph.resize(n+1);
	res.resize(n+1);

	rep (i, 1, n) {
		cin >> ve[i];
	}
	
	rep (i, 1, n) {
		int a;
		cin >> a;

		graph[i+1].push_back({ve[i], a});
		graph[ve[i]].push_back({i+1, a});
	}

	int ans = 0;
	rep2 (i, 1, n) {
		dfs(-1, i, 0);
	}
	rep2 (i, 1, n) {
		ans += res[i];
	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}