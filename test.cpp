#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define sp " "
#define ln "\n"

using namespace std;

int n, m;
V ve;
V pf;

void solve() {

    cin >> n;

    ve.resize(n);
    pf.resize(n + 1);

    rep (i, 0, n) {
        cin >> ve[i];
    }
    rep2 (i, 1, n) {
        pf[i] = pf[i-1] + ve[i-1];
    }

    cin >> m;

    rep (i, 0, m) {
        int a, b;
        cin >> a >> b;

        cout << (pf[max(a, b)] - pf[min(a, b) - 1]) << ln;
    }

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
