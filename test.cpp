#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, l, w;
vector<pii> ve;

int f(int x, int y) {
    //cout << endl;
    auto it = lower_bound(ve.begin(), ve.end(), ( (pii) {x, -1e18} ) );
    auto it2 = upper_bound(ve.begin(), ve.end(), ( (pii) {x+w+1, -1e18} ) );
    int result = 0;
    for (auto a = it; a != it2; a++) {
        pii b = *a;
        //cout << b.F << " " << b.S << endl;
        if (b.S >= y && b.S <= y + l) {
            result++;
        }
    }
    return result;
}

void solve() {

    cin >> n >> l >> w;
    ve.push_back(mp(-1, -1));
    int maximum_x = -1e18;
    int maximum_y = -1e18;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        maximum_x = max(maximum_x, a);
        maximum_y = max(maximum_y, b);
        ve.push_back(mp(a, b));
    }
    sort(ve.begin(), ve.end(), less<pii>());
    int maximum = -1e18;
    //cout << endl;
    //cout << (maximum_x) << " " << (maximum_y) << endl;
    for (int i = 0; i <= maximum_x; i++) {
        for (int j = 0; j <= maximum_y; j++) {
            maximum = max(maximum, f(i, j));
        }
    }
    cout << maximum << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

