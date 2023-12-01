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
    int l = 0, r = 1;
    while (r < n)
    {
        int sum = arr[l] + arr[r];        
        if (sum < m) r++;
        if (sum > m) l++;
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
