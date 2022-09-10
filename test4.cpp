#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "

using namespace std;

int n, m;
vector<int> ve;
set<int> se;

void solve() {

    cin >> n >> m;
    ve.resize(m);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        ve[i] = a;
    }
    int head = ve.front();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        /*for (auto a : se) {
            cerr << a << sp;
        }*/
        //cerr << ln;
        if (i < n-1) {
            se.insert(ve[i]);
        }
        se.insert(ve[i]);
        if (se.size() == n) {
            //cerr << i << ln;
            ans++;
        }
        se.erase(ve[i-(n-1)]);
    }
    cout << ans << ln;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
