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

void solve() {
    string s;
    while (getline(cin, s)) {
        vi record(127 + 1);
        for (int i = 0; i < s.size(); i++) {
            record[s[i]]++;
        }
        
        vp ans;
        for (int i = 0; i <= 127; i++) {
            if (record[i] != 0) {
                ans.push_back({i, record[i]});
            }
        }
        
        sort(ans.begin(), ans.end(), [] (pii x, pii y) {
            if (x.second < y.second) return true;
            if (x.second > y.second) return false;
            if (x.first > y.first) return true;
            if (x.first < y.first) return false;
            return true;
        });
        
        for (auto i : ans) {
            cout << i.first << ' ' << i.second << '\n';
        }
        
        cout << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
