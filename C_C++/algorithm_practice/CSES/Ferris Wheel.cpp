#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

int n, m;
vector<int> arr;

void solve()
{
    cin >> n >> m;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i;
    }

    sort(arr.begin(), arr.end());

    int ptrL = 0, ptrR = arr.size() - 1;
    int ans = 0;
    int now = 0;
    while (ptrL < ptrR)
    {
        now = 0;
        if (now + arr[ptrR] <= m)
        {
            now += arr[ptrR--];
        }
        if (now + arr[ptrL] <= m)
        {
            now += arr[ptrL++];
        }
        ans++;
    }
    ans += ptrL == ptrR;

    cout << ans << '\n'; 
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}