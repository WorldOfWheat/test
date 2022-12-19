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
multiset<int> ms;

void solve() {

    cin >> n >> m;

    rep (i, 0, n) {
        int in;
        cin >> in;

        ms.insert(in);
    }

    int ans = 0;
    while (ms.size()) {
        int k = *ms.rbegin();
        ms.erase(ms.find(k));

        ans++;

        if (ms.empty()) {
            break;
        }

        auto it = ms.upper_bound(m - k);
        if (it == ms.begin()) {
            continue;
        }
        it--;

        ms.erase(it);
    }

    cout << ans << ln;

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;

}

