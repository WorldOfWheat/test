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

struct node {

    int left;
    int right;
    int sum;

};

int n;
V ve;
vector<node> seg;

int getLc(int x) {
    return (x << 1);
}

int getRc(int x) {
    return (x << 1 + 1);
}

void build(int l, int r, int pos) {

    if (l == r) {
        seg[l].sum = ve[pos];
        return;
    }

    int mid = (l + r) >> 1;
    build(l, mid, getLc(pos));
    build(mid + 1, r, getRc(pos));

    seg[pos] += 

}

void solve() {

    cin >> n;
    
    ve.resize(n);
    seg.resize(4 * n + 1);

    rep (i, 0, n) {
        cin >> ve[i];
    }

    

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}