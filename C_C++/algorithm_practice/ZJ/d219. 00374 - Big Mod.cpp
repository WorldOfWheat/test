#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

auto quick_pow = [] (int x, int y, int mod) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= mod;
        }
        y >>= 1;
        x *= x;
        x %= mod;
    }
    return res;
};

void solve() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        cout << quick_pow(n, m, k) << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
