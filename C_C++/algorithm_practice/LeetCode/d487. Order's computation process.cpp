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
typedef vector<vp> v2p;

int f(int n) {
    if (n == 1) {
        cout << 1;
        return 1;
    }
    cout << n << " * ";
    return n * f(n - 1);
}

void solve() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            cout << "0! = 1 = 1\n";
            continue;
        }
        cout << n << "! = ";
        int ans = f(n);
        cout << " = " << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
