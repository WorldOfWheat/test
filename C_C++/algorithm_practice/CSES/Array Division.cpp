#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;

bool check(ll expected_sum) 
{
    // cerr << expected_sum << '\n';
    int result = 1;
    ll current_sum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > expected_sum) return false;
        current_sum += arr[i];
        if (current_sum > expected_sum) 
        {
            current_sum = arr[i];
            result++;
        }
    }

    if (current_sum > expected_sum) result++;

    return result <= m;
}

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    ll l = 0, r = 1e18;
    while (l < r) 
    {
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
