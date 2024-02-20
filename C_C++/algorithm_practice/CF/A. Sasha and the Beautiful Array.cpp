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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += arr[i] - arr[i-1];
        }
        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
