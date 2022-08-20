#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> ve;
int dp[2000+1][2000+1];

void solve() {

    int n;
    cin >> n;
    ve.resize(n);
    for (int i = 0; i< n; i++) {
        cin >> ve[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i-1][j-1] + ve[i-1] < 0) {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max( dp[i-1][j], dp[i-1][j-1] + ve[i-1] );
        }
    }
    //cout << (dp[n][n]) << ln;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cerr << dp[i][j] << sp;
        }
        cerr << ln;
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
