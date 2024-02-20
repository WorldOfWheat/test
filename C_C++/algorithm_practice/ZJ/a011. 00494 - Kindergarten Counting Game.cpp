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

void solve() {
    string s;
    while (getline(cin, s)) {
        char last = ' ';
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isalpha(last) && isalpha(s[i])) {
                ans++;
            }
            last = s[i];
        }
        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
