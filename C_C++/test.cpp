#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;
vector<int> prefix_sum;
vector<int> suffix_sum;

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (n == 1) {
        cout << arr[0] * 2 << '\n';
        return;
    }
    
    sort(arr.begin(), arr.end());

    prefix_sum.resize(n + 1);
    suffix_sum.resize(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
        suffix_sum[i] = suffix_sum[i-1] + arr[n-i];
    }
    
    // for (int i = 1; i <= n; i++) cerr << prefix_sum[i] << ' ';
    // cerr << '\n';
    // for (int i = 1; i <= n; i++) cerr << suffix_sum[i] << ' ';
    // return;
    
    int sum = 0;   
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        
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
