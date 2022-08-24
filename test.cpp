#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<pii>>
#define pii pair<int, string>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

void solve() {

    string str;
    string str2;
    cin >> str >> str2;
    int len = str.length();
    int len2 = str2.length();

    vv dp(len+1, vector<pii>(len2+1));

    rep2 (i, 1, len) {
        rep2 (j, 1, len2) {
            if (str[i-1] == str2[j-1]) {
                dp[i][j].F = dp[i-1][j-1].F + 1;
                dp[i][j].S += dp[i-1][j-1].S + str[i-1];
                continue;
            }
            if (dp[i-1][j].F > dp[i][j-1].F) {
                dp[i][j].F = dp[i-1][j].F;
                dp[i][j].S = dp[i-1][j].S;
            }
            else {
                dp[i][j].F = dp[i][j-1].F;
                dp[i][j].S = dp[i][j-1].S;
            }
        }
    }
    cout << (dp[len][len2].S) << ln;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
