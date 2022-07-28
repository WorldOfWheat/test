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
vector<int> ve_left;
vector<int> ve_right;

void solve() {

    cin >> n >> m;
    ve.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    //
    int mid = n/2;
    for (int i = 0; i <= mid; i++) {
        for (int j = i; j <= mid; j++) {
            ve_left.push_back(ve[i] + ve[j]);
        }
    }
    for (int i = mid+1; i <= n; i++) {
        ve_right.push_back(0 + ve[i]);
    }
    for (int i = mid+1+1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ve_right.push_back(ve[i]+ve[j]);
        }
    }
    /*for (auto a : ve_left) {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : ve_right) {
        cout << a << " ";
    }
    cout << endl;*/
    sort(ve_right.begin(), ve_right.end());
    int ans = 0;
    for (auto a : ve_left) {
        int remain = m - a;
        auto it = lower_bound(ve_right.begin(), ve_right.end(), remain);
        auto it2 = upper_bound(ve_right.begin(), ve_right.end(), remain);
        ans += distance(it, it2);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
