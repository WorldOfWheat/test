#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

int n;
vi arr;
vi dp;

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    dp.resize(n);
    int top = 0;
    for (int i = 0; i < n; i++)
    {
        auto lower = lower_bound(dp.begin(), dp.begin() + top, arr[i]);
        if (lower == dp.begin() + top)
        {
            dp[top++] = arr[i];
            continue;
        }
        *lower = arr[i];
    }
    
    cout << top << '\n';
}

signed main()
{
    fastio;
    solve();
    return 0;
}