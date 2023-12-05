#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define ll long long;
#define pii pair<int, int>;

using namespace std;

int n, m;
vector<int> arr;
vector<int> visited;

void coord_compress(vector<int> &arr) 
{
    vector<int> mapping(arr);
    sort(mapping.begin(), mapping.end());
    mapping.erase(unique(mapping.begin(), mapping.end()));
    
    for (int i = 0; i < arr.size(); i++)
    {
        auto lower = lower_bound(begin(mapping), end(mapping), arr[i]);
        int index = distance(begin(mapping), lower);
        arr[i] = index;        
    }
}

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }

    coord_compress(arr);
    
    visited.resize(2e5 + 5);
    int ans = 0;
    int l = 0, r = 0;
    visited[arr[l]]++;
    while (r < n) 
    {
        while (arr[r] < 1) 
        {
        }
        while ()
    }
    
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
