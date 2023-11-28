#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr.begin(), arr.end());
    
    // for (int i = 0; i < n; i++) cerr << arr[i].first << ' ' << arr[i].second << '\n';
    
    ll ans = 0;
    ll current_time = 0;
    for (int i = 0; i < n; i++)
    {
        pii current = arr[i];
        current_time += current.first;
        ans += current.second    - current_time;
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
