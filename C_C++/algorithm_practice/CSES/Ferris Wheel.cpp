#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n, m;
vi arr;

void solve() 
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    // for (auto i : arr) cerr << i << ' ';
    // cerr << '\n';
    
    int ptr_l = 0, ptr_r = n - 1;
    int ans = 0;
    while (ptr_l <= ptr_r)
    {
        int current_weight = arr[ptr_r--];
        if (current_weight + arr[ptr_l] <= m) ptr_l++;
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
