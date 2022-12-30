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



void solve() {



<<<<<<< HEAD:test.cpp
    rep (i, 0, n) {
        int in;
        cin >> in;
        ve[--in] = i;
        ve2[i] = in;
    }

    int ans = 1;
    rep (i, 1, n) {
        if (ve[i] <= ve[i-1]) {
            ans++; 
        }
    }



=======
>>>>>>> 5e3847d19c8f3e9df4e74403c25636c558b8d0ad:C++/test.cpp
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}
