#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define VS vector<string>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define INF (int) 1e18
#define ln '\n'

using namespace std;

int n;
VS ve;

void solve() {
    cin >> n;
    
    int maxiLen = -INF;
    rep (i, 0, n) {
        string in;
        cin >> in;
        ve.push_back(in);
        maxiLen = max(maxiLen, (int) in.length()); 
    }

    rep (i, 0, maxiLen) {
        rep (j, 0, n) {
            if (ve[j].length() > i && !isdigit(ve[j][i])) {
                 cout << ve[j][i];
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}

