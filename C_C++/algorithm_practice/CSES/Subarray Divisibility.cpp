#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;
map<int, int> ma;

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    ll ans = 0;
    ll current_sum = 0;
    ma[0] = 1;
    for (int i = 0; i < n; i++)
    {
        current_sum += arr[i];
        int mod;
        if (current_sum < 0) 
        {
            // cerr << current_sum << '\t';
            // cerr << (-(current_sum)) / n << '\t';
            mod = current_sum + ((-(current_sum)) / n + 1) * n;
            mod %= n;
        }
        else mod = current_sum % n;
        // cerr << mod << '\n';
        ans += ma[mod];
        ma[mod]++;
    }
    
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}