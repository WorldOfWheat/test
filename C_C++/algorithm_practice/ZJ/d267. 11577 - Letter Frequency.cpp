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
    int n;
    cin >> n;

    string temp;
    getline(cin, temp);
    
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        vi arr(26);
        for (int j = 0; j < s.size(); j++) {
            if (!isalpha(s[j])) {
                continue;
            }
            arr[tolower(s[j]) - 'a']++;
        }

        int maximum = -1e18;
        for (int j = 0; j < 26; j++) {
            maximum = max(maximum, arr[j]);
        }
        for (int j = 0; j < 26; j++) {
            if (arr[j] == maximum) {
                cout << (char) ('a' + j);
            }
        }
        cout << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
