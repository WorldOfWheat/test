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
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> m >> n;
        
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        

        v2i dp(n + 1, vi(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                dp[i][j] += dp[i-1][j - arr[i-1]] + dp[i-1][j];
            }
        }
        
        
        if (dp[n][m] > 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
