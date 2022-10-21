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
V weight;
VV graph;
VV dp;

void dfs(int parent, int now) {

    dp[0][now] = weight[now];
    dp[1][now] = INF;

    for (auto i : graph[now]) {
        if (i == parent) {
            continue;
        }

        dfs(now, i);

        dp[0][now] += min(dp[0][now], dp[1][now]);
        dp[1][now] += min(dp[1][now], dp)
    }

}

void solve() {

    cin >> n;

    weight.resize(n + 1);
    graph.resize(n + 1);
    dp.resize(3, n + 1);

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

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
