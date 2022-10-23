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

int n, m, o, p;
VVP ve;
VV backup;
vector<bool> fatal;
V color;

bool dfs(int now, int _color) {

    if(color[now]) {
        return 1;
    }

    bool res = 1;
    color[now] = _color;
    for(int i : backup[now]){
        if(color[i] == _color) return 0;
        res &= dfs(i, 3 - _color);
    }
    return res;

}

bool check(int x) {

    rep (i, 0, n) {
        backup[i].clear();
        color[i] = 0;
    }

    rep2 (i, 0, x) {
        for (auto i : ve[i]) {
            backup[i.F].push_back(i.S);
            backup[i.S].push_back(i.F);
        }
    }

    bool res = 1;
    rep (i, 0, n) {
        res &= dfs(i, 1);
    }

    return res;

}

void bs(int l, int r) {

    if (check(r)) {
        return;
    }

    while(l != r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    fatal[l] = 1;
    ve[l].clear();

}

void solve() {

    cin >> n >> m;

    ve.resize(n);
    fatal.resize(n);
    backup.resize(n);
    color.resize(n);

    rep (i, 0, m) {
        int a, b;
        cin >> a >> b;

        ve[0].push_back({a, b});
    }

    cin >> o >> p;
    rep2 (i, 1, o) {
        rep (j, 0, p) {
            int a, b;
            cin >> a >> b;

            ve[i].push_back({a, b});
        }
    }

    rep (i, 0, 3) {
        bs(0, o);
    }

    rep2 (i, 1, o) {
        if (fatal[i]) {
            cout << i << ln;
        }
    }

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
