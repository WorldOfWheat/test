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

const V dirX = {1, -1, 0, 0};
const V dirY = {0, 0, 1, -1};

int n, m;
VV graph;
VV vis;
VV dis;

void bfs() {

	queue<pii> qu;
	qu.push({0, 0});

	int res = INF;
	while (qu.size()) {
		pii top = qu.front();
		qu.pop();

		rep (i, 0, 4) {
			int dx = top.F + dirX[i];
			int dy = top.S + dirY[i];

			if (dx < 0 || dx >= n || dy <0 || dy >= m) {
				continue;
			}

			while (graph[dx][dy] == 0) {
				if (vis[dx][dy]) {
					break;
				}
				vis[dx][dy] = true;

				dis[dx][dy] = dis[top.F][top.S] + 1;
				qu.push({dx, dy});

				dx += dirX[i];
				dy += dirY[i];

				if (dx < 0 || dx >= n || dy <0 || dy >= m) {
					break;
				}
			}
		}
	}

	dis[n-1][m-1]--;

	cout << (dis[n-1][m-1]) << ln;
}

void solve() {

	cin >> n >> m;

	graph.resize(n, V(m));
	vis.resize(n, V(m));
	dis.resize(n, V(m));

	rep (i, 0, n) {
		string str;
		cin >> str;

		rep (j, 0, m) {
			graph[i][j] = str[j] - '0';
		}
	}

	bfs();

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}