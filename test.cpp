#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define INF (int) 1e18

using namespace std;

void solve() {

<<<<<<< HEAD
    
=======
    cin >> n;

    int k = 5;
    int ans = 0;
    while (k <= n) {
        ans += (n / k);
        k *= 5;
    }
>>>>>>> 492307b758afcbfc064cbcb4f496a3e154559f14

    cout << ans << '\n';

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
