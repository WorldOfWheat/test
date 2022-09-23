#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define vv vector<vector<int>>
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
V dp;
deque<int> de;

void solve() {
	
	int n, m;
	cin >> n >> m;

	m++;

	ve.resize(n);
	dp.resize(n+1);

	rep (i, 0, n) {
		cin >> ve[i];
	}

	

	rep (i, 0, n) {						
		while (de.size() && de.front() < i - 2*m) {
			de.pop_front();
		}		

		while (de.size() && ve[de.back()] >= ve[i]) {
			de.pop_back();
		}

		de.push_back(i);
	

	}

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}