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

VV ve;
vector<bool> vis;
V dis;
queue<int> bfs;

void solve() {

	int n, m;
	cin >> n >> m;

	ve.resize(n, V(n));
	vis.resize(n);
	dis.resize(n);

	int k;
	cin >> k;

	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;

		ve[a].push_back(b);
	}

	int ans = 0;
	int ans2 = 0;

	bfs.push(k);
	vis[k] = true;
	while (bfs.size()) {
		int top = bfs.front();
		bfs.pop();

		for (auto i : ve[top]) {
			if (vis[i]) {
				continue;
			}

			vis[i] = true;
			dis[i] = dis[top] + 1;
			bfs.push(i);

			ans++;
			ans2 += dis[i];
		}
	}

	cout << (ans) << ln << ans2 << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}