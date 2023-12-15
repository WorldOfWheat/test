#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;
vector<int> record;

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
    
    record.resize(2e5 + 1, 0);
    int count = 0;
    int r = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) 
    {
        while (r < n && count <= m) 
        {
            r++;
            if (record[arr[r]] == 0) count++;
            record[arr[r]]++;
        }

        ans += r - i;

        record[arr[i]]--;
        if (record[arr[i]] == 0) count--;
    }
    
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
