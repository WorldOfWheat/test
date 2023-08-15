#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define rep_each(x, y) for (auto &x : y)
#define INF INT64_MAX
#define b2e(x) x.begin(), x.end()

using namespace std;

int n, m, k;
multiset<int> ms;
multiset<int> ms2;

void solve()
{
    cin >> n >> m >> k;

    rep (i, 0, n)
    {
        int tmp;
        cin >> tmp;
        ms.insert(tmp);
    }
    rep (i, 0, m)
    {
        int tmp;
        cin >> tmp;
        ms2.insert(tmp);
    }

    int ans = 0;
    rep_each(i, ms)
    {
        int a = max(0ll, i - k);
        auto lower = ms2.lower_bound(a);
        if (lower != ms2.end() && abs(*lower - i) <= k)
        {
            ans++;
            ms2.erase(lower);
        }
    }

    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}