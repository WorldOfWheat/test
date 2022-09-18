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
V pf;
V sf;

int dfs(int l, int r) {

    if (l >= r) {
        return ve[l];
    }

    int mid = (l + r) / 2;
    int res = max(dfs(l, mid), dfs(mid+1, r));

    

}

void solve() {
	
    int n;
    cin >> n;

    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }

    pf.resize(n+1);
    sf.resize(n+1);

    rep2 (i, 1, n) {
        pf[i] = pf[i-1] + ve[i-1];
        sf[i] = sf[i-1] + ve[n-i];
    }


}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
