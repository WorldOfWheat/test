#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define js(x, y) for(int x = y / 2; x > 0; x--)
#define sp " "
#define ln "\n"

using namespace std;

V ve;

void solve() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ve = {1, 5, 10, 20, 40, 80, 90, 100};

    if (ve[0] > n) {
        cout << (ve[0]) << ln;
        exit(0);
    }
    
    int pos = 0;
    js(i, ve.size() - 1) {
        while (pos + i < ve.size() && ve[pos + i] < n) {
            pos += i;
        }
    }

    if (pos + 1 >= ve.size()) {
        cout << "null" << ln;
        exit(0);
    }
    cout << (ve[pos + 1]) << ln;

}

signed main() {

    solve();

    return 0;

}