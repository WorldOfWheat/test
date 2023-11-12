#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;

void solve()
{
    cin >> n;

    arr.resize(n);

    for (auto &i : arr)
    {
        cin >> i;
    }

    ll ans = -1e18;
    ll now = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        now = max((ll) arr[i], now + arr[i]);
        ans = max(now, ans);
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