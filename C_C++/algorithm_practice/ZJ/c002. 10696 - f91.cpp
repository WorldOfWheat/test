#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<bool> vb;
typedef vector<vb> v2b;

int n;

int f(int n) {
    if (n <= 100) {
        return f(f(n + 11));
    }
    if (n >= 101) {
        return n - 10;
    }
}

void solve() {
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        cout << "f91(" << n << ") = " << f(n) << '\n';        
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
