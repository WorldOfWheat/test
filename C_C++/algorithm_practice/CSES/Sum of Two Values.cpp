#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<pii> arr;

void solve()
{
    cin >> n >> m;

    arr.resize(n);

    for (int i = 0; i < arr.size(); i++) 
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    int ptrL = 0, ptrR = arr.size() - 1;
    ll sum = 0;
    while (ptrL < ptrR) 
    {
        if (sum == m) break;
        sum = arr[ptrL].first + arr[ptrR].first;
        if (sum < m) ptrL++;
        if (sum > m) ptrR--;
    }

    int ans1 = arr[ptrL].second, ans2 = arr[ptrR].second;
    if (ans1 > ans2) swap(ans1, ans2);

    if (sum == m) cout << ans1 << " " << ans2 << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}