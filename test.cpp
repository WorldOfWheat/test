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

vector<int> ve;
V dp;
int bin;

int dfs(int x, int y) {

	

}

void solve() {

	int n;

	cin >> n;

	bin = 1 << n;

	ve.resize(bin);
	dp.resize(bin + 1, -1);

	rep (i, 0, bin) {
		cin >> ve[i];
	}

	cout << (dfs(bin-1, n));

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}