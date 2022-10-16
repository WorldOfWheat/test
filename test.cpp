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
VP graph;
V outdeg;
V cnt;
int res;

void bfs() {



}

void solve() {

	cin >> n;

	graph.resize(n+1);
	outdeg.resize(n+1);
	cnt.resize(n+1);

	rep2 (i, 2, n) {
		cin >> graph[i].F;
		outdeg[graph[i].F]++;
	}
	rep2 (i, 2, n) {
		cin >> graph[i].S;
	}

	bfs();

	cout << (res) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}