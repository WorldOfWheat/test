#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> st;
        int ans = 0;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                st.push(c);
            }
            else {
                if (st.size() && st.top() == '(') {
                    ans++;
                    st.pop();
                }
                else {
                    flag = false;
                }
            }
        }
        
        if (flag && st.empty()) {
            cout << ans << '\n';
        } else {
            cout << "0" << '\n';
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
