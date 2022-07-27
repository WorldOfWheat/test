#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m;
vector<int> ve;

bool check(int x) {
    int k = 1;
    for (int i = 1; i <= m; i++) {
        //cout << k << " " << x << " " << (k+x) << "\n";
        auto it = lower_bound(ve.begin(), ve.end(), k+x);
        if (it == ve.end()) {
            return true;
        }
        k = *it;
    }
    return (k >= *ve.rbegin());
}

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ve.push_back(a);
    }
    sort(ve.begin(), ve.end(), less<int>());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
