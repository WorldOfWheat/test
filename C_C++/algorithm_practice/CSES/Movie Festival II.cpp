#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug_container(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n, m;
vp arr;
multiset<int> ms;

bool cmp(pii x, pii y) 
{
    if (x.second < y.second) return true;
    if (x.second > y.second) return false;
    if (x.first < y.first) return false;
    if (x.first > y.first) return true;
    return true;
}

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    
    sort(arr.begin(), arr.end(), cmp);
    
    int ans = 0;
    for (int i = 0; i < m; i++) ms.insert(0);
    for (int i = 0; i < n; i++) 
    {
        pii current = arr[i];
        auto lower = ms.upper_bound(current.first);
        if (lower != ms.begin())
        {
            lower--;
            ms.erase(lower);
            ms.insert(current.second);
            ans++;
        }
    }
    
    cout << ans << '\n';
}

int main()
{
    fastio;

    solve();

    return 0;
}