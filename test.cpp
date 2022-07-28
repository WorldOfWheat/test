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
    if (n == 1) {
        cout << (m == ve[1]) << endl;
        return;
    }
    int mid = n/2;
    bitset<20+1> bs;
    int k = 0;
    while (bs.count() != mid) {
        bs = k;
        k++;
        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < mid; i++) {
            //cout << bs[i];
            if (bs[i]) {
                sum += ve[i+1];
                sum2 += ve[i+1+mid];
            }
        }
        //cout << endl;
        ve_left.push_back(sum);
        ve_right.push_back(sum2);
    }
    /*
    cout << endl;
    for (auto a : ve_left) {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : ve_right) {
        cout << a << " ";
    }*/
    sort(ve_right.begin(), ve_right.end());
    int ans = 0;
    for (auto a : ve_left) {
        int remain = m - a;
        auto it = lower_bound(ve_right.begin(), ve_right.end(), remain);
        auto it2 = upper_bound(ve_right.begin(), ve_right.end(), remain);
        //cout << (distance(it, it2)) << endl;
        ans += distance(it, it2);
    }
    cout << ans << endl;

    //cout << mid << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
