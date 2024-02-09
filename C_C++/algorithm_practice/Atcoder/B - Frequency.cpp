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
int* freq;

void solve() {
    cin >> s;
    
    freq = new int[26]();
    
    int maximum = 0;
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        maximum = max(maximum, freq[s[i] - 'a']);
    }
    
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maximum) {
            cout << (char) (i + 'a') << '\n';
            return;
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
