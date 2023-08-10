#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
vector<ll> arr;
ll ans = INT64_MAX;

void dfs(ll sum, ll sum2, int index)
{
    if (index == n)
    {
        ans = min(ans, abs(sum - sum2));
        return;
    }

    dfs(sum + arr[index], sum2, index + 1);
    dfs(sum, sum2 + arr[index], index + 1);
}

void solve()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dfs(0, 0, 0);

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