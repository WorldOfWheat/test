#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;
vector<ll> prefix_sum;
map<ll, int> ma;

void solve()
{
    cin >> n >> m;

    arr.resize(n);
    prefix_sum.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ma[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) 
    {
        prefix_sum[i+1] = prefix_sum[i] + arr[i];
        ll remain = m - prefix_sum[i+1];
        ans += ma[-remain];
        ma[prefix_sum[i+1]]++;
    }
    
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}