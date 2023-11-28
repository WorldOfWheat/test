#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;

ll maximum_make(ll time)
{
    ll sum = 0;
    for (int i = 0; i < arr.size(); i++) 
    {
        sum += time / arr[i];
        if (sum > m) break; // 用來防止 overflow
    }
    return sum;
}

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    ll l = 0, r = 1e18;
    while (l < r)
    {
        ll mid = l + ((r - l) >> 1ll);
        cerr << l << ' ' << mid << ' ' << r << ' ' << maximum_make(mid) << '\n';
        if (maximum_make(mid) >= m) r = mid;
        else l = mid + 1;
    }
    
    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
