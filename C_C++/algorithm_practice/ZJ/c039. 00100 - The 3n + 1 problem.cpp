#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

map<int, int> table;

int f(int n) {
    if (n == 1) {
        return 1;
    }
    
    if (table[n] != 0) {
        return table[n];
    }

    if (n % 2) {
        return table[n] = f(3 * n + 1) + 1;
    }
    else {
        return table[n] = f(n / 2) + 1;
    }
}

void solve() {
    int n, m;
    while (cin >> n >> m) {
        cout << n << ' ' << m << ' ';

        if (n > m) swap(n, m);
        
        int ans = -1e18;
        for (int i = n; i <= m; i++) {
            ans = max(ans, f(i));
        }
        
        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
