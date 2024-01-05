#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n, m, k;
vi arr;
vi arr2;

int check(int sum)
{
    int current_sum = 0;
    int count = 1;
    for (int i = 0; i < n; i++) 
    {
        current_sum += arr[i];
        if (current_sum > sum) 
        {
            current_sum = arr[i];
            count++;
        }
    }
    return count;
}

int binary_search()
{
    int l = 0, r = 1e18;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid) <= k) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve() 
{
    cin >> n >> m >> k;

    arr.resize(n);
    arr2.resize(m);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];
    

    if (m == 1 || m == 0) 
    {
        int sum = binary_search();
        int ans = -1e18;

        int current_sum = 0;
        for (int i = 0; i < n; i++) 
        {
            current_sum += arr[i];
            if (current_sum > sum) 
            {
                current_sum = arr[i];
            }
            ans = max(ans, current_sum);
        }
        cout << ans << '\n';
        return;
    }
    
    int sum = binary_search();
    vi maximum_permutation(n);
    copy(arr.begin(), arr.end(), maximum_permutation.begin());

    for (int i = 0; i < m - 1; i++) 
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(arr[arr2[i]], arr[arr2[j]]);
            int res = binary_search();
            if (sum > res) 
            {
                sum = res;
                copy(arr.begin(), arr.end(), maximum_permutation.begin());
            }
            swap(arr[arr2[i]], arr[arr2[j]]);
        }
    }
    
    // for (int i = 0; i < n; i++) cerr << maximum_permutation[i] << ' ';

    int ans = -1e18;
    int current_sum = 0;
    for (int i = 0; i < n; i++) 
    {
        current_sum += maximum_permutation[i];
        if (current_sum > sum) 
        {
            current_sum = maximum_permutation[i];
        }
        ans = max(ans, current_sum);
    }
    
    cout << ans << '\n';
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
