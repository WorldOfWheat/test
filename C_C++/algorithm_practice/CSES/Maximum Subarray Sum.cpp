#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug_container(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';
#define input_arr(n, arr) for (int i = 0; i < n; i++) cin >> arr[i];

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n;
vi arr;

ll f(int l, int r) 
{
    if (l + 1 >= r) return arr[l];

    int mid = (l + r) >> 1;
    ll left_part = f(l, mid);
    ll right_part = f(mid, r);
    ll maximum = max(left_part, right_part);

    ll left_maximum = -1e18, right_maximum = -1e18;
    ll current_sum = 0;
    for (int i = mid - 1; i >= l; i--) 
    {
        current_sum += arr[i];
        left_maximum = max(left_maximum, current_sum);
    }
    current_sum = 0;
    for (int i = mid; i < r; i++) 
    {
        current_sum += arr[i];
        right_maximum = max(right_maximum, current_sum);
    }
    
    return max({left_part, right_part, left_maximum + right_maximum});
}

void solve()
{
    cin >> n;
    
    arr.resize(n);
    input_arr(n, arr);

    cout << f(0, n) << '\n';
}

int main()
{
    fastio;

    solve();

    return 0;
}