#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug_container(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int n,m;
vi arr;
vl prefix_sum;

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    prefix_sum.resize(n + 1);
    for (int i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n;
        while (l < r) 
        {
            int mid = (l + r) >> 1;
            if (prefix_sum[mid] - prefix_sum[i] >= m) r = mid;
            else l = mid + 1;
        }
        if (prefix_sum[l] - prefix_sum[i] == m) ans++;
    }
    
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
