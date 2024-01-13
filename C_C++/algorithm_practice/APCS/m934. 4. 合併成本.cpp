#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;

int n;
vi arr;
vvp dp(100 + 1, vp(100+1, {-1, -1e18})); 

pii f(int left, int right)
{
    if (left == right) return {0, arr[left]};
    if (dp[left][right].second != -1e18) return dp[left][right];

    pii res = {1e18, -1};
    for (int i = left; i <= right - 1; i++)
    {
        pii left_part = f(left, i);
        pii right_part = f(i+1, right);
        int cost = left_part.first + right_part.first + abs(left_part.second - right_part.second);
        if (res.first > cost)
        {
            res.first = cost;
            res.second = left_part.second + right_part.second;
        }
    }
    return dp[left][right]=res;
}

void solve() 
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << f(0, n-1).first << '\n';
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
