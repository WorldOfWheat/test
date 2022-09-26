#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define VV vector<vector<int>>
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

	ve.resize(n);
	dp.resize(n+1);

	rep (i, 0, n) {
		cin >> ve[i];
	}

	rep2 (i, 1, n) {
		int top = ve[i-1];

		if (i <= m + 1) {
			dp[i] = top;
		}
		else {
			while (de.front() < i - 2 * m - 1) {
				de.pop_front();
			}
			dp[i] = dp[de.front()] + top;
		}

		while (de.size() && dp[de.back()] >= dp[i]) {
			de.pop_back();
		}

		de.push_back(i);
	}

	cout << (*min_element(dp.begin() + n - m, dp.end())) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}