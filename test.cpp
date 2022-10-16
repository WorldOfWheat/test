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
V outdeg;
V cnt;

int bfs() {

	queue<int> qu;

	rep2 (i, 1, n) {
		if (outdeg[i] == 0) {
			qu.push(i);
			cnt[i] = n - 1;
		}
	}

	int res = 0;
	while (qu.size()) {
		int top = qu.front();
		qu.pop();

		for (auto i : graph[top]) {
			if (i.F == top) {
				continue;
			}

			res += cnt[top] * i.S;

			cnt[i.F] += (cnt[top] - 1) + cnt[top];
		}
	}

	return res;

}

void solve() {

	cin >> n;

	ve.resize(n+1);
	graph.resize(n+1);
	outdeg.resize(n+1);
	cnt.resize(n+1);

	rep2 (i, 2, n) {
		cin >> ve[i];
		outdeg[ve[i]]++;
	}

	rep2 (i, 2, n) {
		int a;
		cin >> a;

		graph[i].push_back({ve[i], a});
		graph[ve[i]].push_back({i, a});
	}

	cout << bfs() << ln << ln;

	rep2 (i, 1, n) {
		cerr << cnt[i] << sp;
	}

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}
