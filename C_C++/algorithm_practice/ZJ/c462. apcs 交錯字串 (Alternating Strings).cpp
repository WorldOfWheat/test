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

void solve() {
    int n;
    string s;
    
    cin >> n >> s;
    
    vi arr(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }
    
    vi arr2;
    int counter = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1]) {
            arr2.push_back(counter);
            counter = 1;
        }
        else {
            counter++;
        }
    }
    arr2.push_back(counter);
    
    int ans = 0;
    counter = 0;
    for (int i = 0; i < arr2.size(); i++) {
        // cerr << arr2[i] << ' ';
        if (arr2[i] < n) {
            counter = 0;
        }
        if (arr2[i] > n) {
            counter++;
            ans = max(ans, counter);
            counter = 1;
        }
        if (arr2[i] == n) {
            counter++;
        }
        ans = max(ans, counter);
    }
    
    cout << n * ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
