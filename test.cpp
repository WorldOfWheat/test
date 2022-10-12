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
VVP graph;
V cnt;
int ans, sum;
bool flag = true;

void dfs(int now) {

	for (auto i : graph[now]) {
		int top = i.F;
		dfs(top);
		sum += min(cnt[top], n - cnt[top]) * i.S;
		cnt[now] += cnt[top];
	}

	cnt[now]++;
	if (cnt[now] >= n / 2 && flag) {
		ans = now;
		flag = false;
	}

}

void solve() {

	cin >> n;

	graph.resize(n);
	cnt.resize(n);

	rep (i, 0, n-1) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back({i+1, b});
	}

	dfs(0);

	cout << ans << ln << sum << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}