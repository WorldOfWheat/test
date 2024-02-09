#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;

void solve() {
    int n, m;
    cin >> n >> m;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            arr[i] += a;
        }
    }
    
    int current = m;
    for (int i = 0; i < n; i++) {
        current -= arr[i];
        if (current < 0) {
            cout << i + 1 << '\n';
            return;
        }
        current += m;
    }
    cout << -1 << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
