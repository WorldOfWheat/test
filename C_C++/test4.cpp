#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<pair<int, int>> arr;
map<int, int> ma;

void solve()
{
    cin >> n;

    arr.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++)
    {
        auto it = prev(upper_bound(arr.begin(), arr.end(), arr[i].second));

        int maximum_left = distance(arr.begin(), )
        int l = i + 1;
        int r = n;
        while (l < r)
        {
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}