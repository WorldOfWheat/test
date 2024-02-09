#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;

string s;

void solve() {
    cin >> s;
    if (islower(s[0])) {
        cout << "No\n";
        return;
    }
    for (int i = 1; i < s.length(); i++) {
        if (isupper(s[i])) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    fastio;
    solve();
    return 0;
}
