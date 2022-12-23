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
#define ln '\n'

using namespace std;

int n, m;
set<int> se;
multiset<int> ms;

void solve() {

    cin >> n >> m; 

    se.insert(0);
    se.insert(n);
    ms.insert(n);

    rep (i, 0, m) {
        int in;
        cin >> in;

        auto it = prev(se.lower_bound(in));
        auto it2 = se.lower_bound(in);
        int k = *it2 - *it;

        ms.erase(ms.lower_bound(k));

        int middleToLeft = in - (*it);
        int middleToRight = (*it2) - in;

        se.insert(in);
        ms.insert(middleToLeft);
        ms.insert(middleToRight);

        cout << *(ms.rbegin()) << ln;

    }

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;

}

