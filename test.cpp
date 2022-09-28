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

struct player {
	int start;
	int end;
	int value;
};

vector<player> ve;
V dp;

void solve() {

	int n;

	cin >> n;

	ve.resize(n+1);
	dp.resize(n+1);

	rep2 (i, 1, n) {
		cin >> ve[i].start >> ve[i].end >> ve[i].value;
	}

	ve[0].end = -1;

	sort(ve.begin(), ve.end(), [](player x, player y) {
		return x.end < y.end;
	});

	dp[0] = 0;

	rep2 (i, 1, n) {
		player top = ve[i];

		int j = 0;
		for (int jump = i / 2; jump >= 1; jump /= 2) {
			while (j + jump < i && ve[j+jump].end < top.start) {
				j += jump;
			}
		}
	
		cerr << j << ln;

		dp[i] = dp[j] + top.value;
		dp[i] = max(dp[i], dp[i-1]);
	}

	cout << (dp[n]) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}