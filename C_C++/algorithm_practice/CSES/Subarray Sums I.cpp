#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int ans = 0;
    int l = 0, r = 0;
    int sum = arr[r];
    while (r < n)
    {
        if (sum == m) 
        {
            ans++;
            r++;
            sum += arr[r];
        }
        
        while (sum < m) 
        {
            r++;
            sum += arr[r];
        }
        while (sum > m) 
        {
            sum -= arr[l];
            l++;
        }
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