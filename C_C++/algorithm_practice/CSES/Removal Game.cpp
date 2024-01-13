#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;

int n;
vi arr;
vi prefix_sum;
vvi dp(5000+1, vi(5000+1, -1));

int f(int left, int right)
{
    if (left == right) return arr[left];
        if (dp[left][right] != -1) return dp[left][right];

    int left_part = arr[left] + (prefix_sum[right + 1] - prefix_sum[left + 1] - f(left+1, right));
    int right_part = arr[right] + (prefix_sum[right] - prefix_sum[left] - f(left, right-1));
    return dp[left][right] = max(left_part, right_part);
}

void solve()
{
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    prefix_sum.resize(n + 1);
    partial_sum(arr.begin(), arr.end(), prefix_sum.begin() + 1);
    
    cout << f(0, n-1) << '\n';
}

signed main() 
{
    fastio;
    solve();
    return 0;
}

// ##############################################################################################

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;

int n;
vi arr;
vi prefix_sum;
vvi dp(5000+1, vi(5000+1));

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    prefix_sum.resize(n + 1);
    partial_sum(arr.begin(), arr.end(), prefix_sum.begin() + 1);
    

    for (int i = 1; i <= n; i++) dp[i][i] = arr[i-1];
    
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i; j++) 
        {
            dp[1+j][1+i+j] = max(arr[1-1+j] + (prefix_sum[1+i+j] - prefix_sum[1+j] - dp[1+1+j][1+i+j]), arr[1+i-1+j] + (prefix_sum[i+j] - prefix_sum[1-1+j] - dp[1+j][i+j]));
        }
    }
    
    cout << dp[1][n] << '\n';
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
