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
typedef vector<bool> vb;
typedef vector<vb> v2b;

int n, m;
vi arr;

void solve() {
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    v2i dp(m + 2, vi(n + 1, 0));
    for (int i = 0; i <= m; i++){
        for (int j = 1; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = max(dp[i][j-1] + arr[j-1], arr[j-1]);
                continue;
            }
            dp[i][j] = max({dp[i-1][j-1], dp[i][j-1] + arr[j-1]});
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= m; i++){
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
