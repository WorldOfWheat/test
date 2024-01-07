#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int t;
int n;

pii cal(int x)
{
    int left = 0, right = 0;
    while (x > 0) 
    {
        if (x & 1) right++;
        else left++;
        x >>= 1;
    }
    return {left, right-1};
}

void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        pii ans = cal(n);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}

signed main()
{
    fastio;
    solve();
    return 0;
}