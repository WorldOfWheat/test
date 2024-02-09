#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;

void solve() {
    int n;
    while (cin >> n) {
        string s;
        for (int i = 0; i < n; i++) {
            char a;
            cin >> a;
            s.push_back(a);
        }
        
        if (n == 1) {
            cout << s << '\n';
            continue;
        }
        
        sort(s.begin(), s.end());

        int size = s.length();
        int ans = -1e18;
        do {
            int num_front = stol(s.substr(0, size / 2));
            int num_back = stol(s.substr(size / 2));
            ans = max(ans, num_front * num_back);

        } while (next_permutation(s.begin(), s.end()));

        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
