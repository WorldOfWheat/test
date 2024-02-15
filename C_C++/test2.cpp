#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;

void build(v2i& st, vi& arr) {
    for (int i = 0; i < arr.size(); i++) {
        st[0][i] = arr[i];        
    }
    for (int i = 1; i < 30; i++) {
        for (int j = 0; j + (1 << i) < arr.size(); j++) {
            st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i - 1))]);            
        }
    }        
}

int query(v2i& st, int l, int r) {
    int res = -1e18;
    for (int i = 30; i >= 0; i--) {
        if ((1 << i) <= r - l) {
            cerr << (1 << i) << ' ';
            res = max(res, st[i][l]);
            cerr << res << '\n';
            l += (1 << i);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    v2i sparse_table(30 + 1, vi(n + 1));
    build(sparse_table, arr);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(sparse_table, a - 1, b) << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
