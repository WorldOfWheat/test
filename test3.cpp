#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "

using namespace std;

string key = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int n, m;
multiset<string> se;

void solve() {

    cin >> n >> m;
    key = key.substr(0, n);
    for (int i = 0; i < m; i++) {
        char last = 'z';
        char a;
        stringstream ss;
        while (a = getchar()) {
            if (a == '\n') {
                break;
            }
            if (a != last) {
                ss << a;
            }
            last = a;
        }
        se.insert(ss.str());
    }
    int ans = 0;
    for (auto it = se.begin(); it != se.end(); it++) {
        string top = *it;
        int len = top.length();
        string remain = key.substr(len);
        //cerr << remain << ln;
        auto it_low = se.lower_bound(remain);
        auto it_high = se.upper_bound(remain);
        ans += distance(it_low, it_high);
    }
    cout << ans << ln;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
