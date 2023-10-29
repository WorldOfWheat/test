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
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int mid;
    if (n % 2) mid = arr[n / 2];
    else mid = (arr[n / 2] + arr[n / 2 - 1]) / 2;

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += abs(arr[i] - mid);

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}