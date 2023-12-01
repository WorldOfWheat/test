#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;
vector<ll> prefix_sum;
vector<ll> suffix_sum;

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (n == 1) {
        cout << arr[0] * 2 << '\n';
        return;
    }
    
    sort(arr.begin(), arr.end());

    prefix_sum.resize(n + 1);
    suffix_sum.resize(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
        suffix_sum[n-i] = suffix_sum[n-i+1] + arr[n-i];
    }
    
    // for (int i = 1; i <= n; i++) cerr << prefix_sum[i] << ' ';
    // cerr << '\n';
    // for (int i = 0; i < n; i++) cerr << suffix_sum[i] << ' ';
    // cerr << '\n';
    
    int l = 1, r = n - 1;
    while (l < r)
    {
        // cerr << l << ' ' << r << '\n';
        // cerr << '#' << prefix_sum[l] << ' ' << suffix_sum[r] << '\n';
        if (prefix_sum[l] <= suffix_sum[r]) l++;
        else r--;
    }
    // cerr << '#' << prefix_sum[l] << ' ' << suffix_sum[r] << '\n';
    ll ans;
    if (prefix_sum[l] > suffix_sum[r])
    {
        ans = prefix_sum[l] * 2;
        if (l != 1) ans -= abs(min(prefix_sum[l] - suffix_sum[r], prefix_sum[l-1]));
    }
    else {
        ans = suffix_sum[l] * 2;
        if (r != n-1) ans -= abs(min(prefix_sum[l] - suffix_sum[r], suffix_sum[r+1]));
    }
    // int ans = max(prefix_sum[l], suffix_sum[r]) * 2;

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
