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
    
    record.resize((int) 2e5 + 5);
    int l = 0, r = 0;
    ll ans = 0;
    while (r < n) 
    {
        cerr << l << ' ' << r << '\n';
        if (record[arr[r]] <= m)
        {
            record[arr[r]]++;
            r++;
        }
        else 
        {
            record[arr[l]]--;
            l++;
        }
        ans++;            
    }
    
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
