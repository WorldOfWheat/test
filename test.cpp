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

int cnt;
V dsu;
V ve;

int query(int x) {
	if (x == dsu[x]) {
		return x;
	}

	return dsu[x] = query(dsu[x]); 
}

void update(int x, int y) {
	int a = query(x);
	int b = query(y);

	if (a != b) {
		cnt++;
	}

	dsu[a] = b;
}

void solve() {

	int n, m;
	cin >> n >> m;

	dsu.resize(n);
	ve.resize(n);

	rep (i, 0, n) {
		dsu[i] = i;
	}

	rep (i, 0, n) {
		cin >> ve[i];

		if (ve[i] == 0) {
			continue;
		}

		if (i >= 0 && (ve[i-1] == 1)) {
			update(i-1, i);
		} 
	}

	cout << cnt << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}