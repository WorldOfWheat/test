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
    int n;
    cin >> n;
    
    string s;
    getline(cin, s);

    vi record(26);
    while (n--) {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (!isalpha(s[i])) {
                continue;
            }
            s[i] = toupper(s[i]);
            record[s[i] - 'A']++;
        }
    }
    
    vp ans;
    for (int i = 0; i < 26; i++) {
        if (record[i] == 0) {
            continue;
        }
        ans.push_back({i, record[i]});
    }
    
    sort(ans.begin(), ans.end(), [](pii x, pii y) {
        if (x.second > y.second) return true;
        if (x.second < y.second) return false;
        if (x.first < y.first) return true;
        if (x.first > y.first) return false;
        return true;
    });
    
    for (auto i : ans) {
        cout << (char) (i.first + 'A') << ' ' << i.second << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
