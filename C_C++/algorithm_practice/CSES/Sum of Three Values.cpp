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
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;
        int sum = arr[i].first + arr[l].first + arr[r].first;
        while (l < r && sum != m)
        {
            if (sum < m) l++;
            if (sum > m) r--;
            sum = arr[i].first + arr[l].first + arr[r].first;
        }
        if (l != r && sum == m ) 
        {
            cout << arr[l].second+1 << ' ' << arr[r].second+1 << ' ' << arr[i].second+1 << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
