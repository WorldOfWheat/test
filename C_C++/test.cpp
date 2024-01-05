#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n;
vi arr;
vi dp;

bool f(int current_sum)
{
    if (current_sum == 0) return true;
    
    bool can_crafted = false;
    for (int i = 0; i < n; i++) 
    {
        if (current_sum - arr[i] < 0) continue;
        if (f(current_sum - arr[i])) 
        {
            dp[current_sum] = true;
            can_crafted = true;
            break;
        }
    }
    
    return can_crafted;
}

void solve() 
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    dp.resize(sum + 1);
    
    f(sum);

    for (int i = 1; i <= sum; i++)
    {
        cerr << dp[i] << ' ';
    }
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int ans = 1;
    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            if (arr[j] == 0) 
            {
                arr[j] = i;
                if (j != 0 && abs(arr[j] - arr[j-1]) <= 1) count++; 
                if (j != n-1 && abs(arr[j] - arr[j+1]) <= 1) count++; 
                arr[j] = 0;
            }
        }
        ans *= count;
        ans %= MOD;
    }
    
    cout << ans << '\n';
}

int main() 
{
    fastio;
    solve();
    return 0;
}
