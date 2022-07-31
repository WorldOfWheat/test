#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m, p;
vector<int> ve;
vector<pii> ve_left;
vector<pii> ve_right;
int mid;

vector<int> table(25+1);
int fact(int x) {
    if (table[x] != -1) {
        return table[x];
    }
    int a = fact(x-1) * x;
    table[x] = a;
    return a;
}
void dfs_left(int x, int y, int z) {
    //cout << x << " " << y << " " << z << endl;
    if (x == mid) {
        //cout << y << endl;
        ve_left.push_back(mp(y, z));
        return;
    }
    dfs_left(x+1, y, z);
    dfs_left(x+1, y+ve[x], z);
    if (z < m) dfs_left(x+1, y+fact(ve[x]), z+1);
}

void dfs_right(int x, int y, int z) {
    if (x == mid+n%2) {
        ve_right.push_back(mp(y, z));
        return;
    }
    dfs_right(x+1, y, z);
    dfs_right(x+1, y+ve[x+mid+1], z);
    if (z < m) dfs_right(x+1, y+fact(ve[x+mid+1]), z+1);
}

void solve() {

    fill(table.begin(), table.end(), -1);
    table[1] = 1;

    cin >> n >> m >> p;
    ve.resize(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }

    //sort(ve.begin(), ve.end());
    //ve.erase( unique(ve.begin(), ve.end()), ve.end());

    mid = n / 2;
    dfs_left(1, 0, 0);
    dfs_left(1, ve[mid], 0);
    if (1 <= m) dfs_left(1, fact(ve[mid]), 1);

    dfs_right(1, 0, 0);
    dfs_right(1, ve[mid+1], 0);
    if (1 <= m) dfs_right(1, fact(ve[mid+1]), 1);

    sort(ve_left.begin(), ve_left.end());
    sort(ve_right.begin(), ve_right.end());

/*
    for (auto a : ve_left) {
        cout << a.F << " ";
    }
    cout << endl;
    for (auto a : ve_right) {
        cout << a.F << " ";
    }
    cout << endl;
*/
    int ans = 0;
    for (auto a : ve_left) {
        int remain = p - a.F;
        //cout <<remain << endl;
        auto it = lower_bound(ve_right.begin(), ve_right.end(), (pair<int, int>) {remain, -2ll << 31} );
        auto it2 = upper_bound(ve_right.begin(), ve_right.end(), (pair<int, int>) {remain, 2ll << 31} );
        cout << (a.S) << " " << ( (*it).S ) << endl;
        if ( a.S + (*it).S <= m) ans += distance(it, it2);
    }
    cout << ans << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
