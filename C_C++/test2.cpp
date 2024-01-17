#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;

struct project
{
    int start_time;
    int end_time;
    int reward;
};

int n;
vector<project> arr;

void coordinate_compress(vector<project>* arr)
{
    vi rank;    
    for (int i = 0; i < n; i++) 
    {
        rank.emplace_back((*arr)[i].start_time);
        rank.emplace_back((*arr)[i].end_time);
    }
    
    sort(rank.begin(), rank.end());
    rank.erase(unique(rank.begin(), rank.end()), rank.end());
    
    for (int i = 0; i < n; i++)
    {
        auto lower = lower_bound(rank.begin(), rank.end(), (*arr)[i].start_time);
        auto lower2 = lower_bound(rank.begin(), rank.end(), (*arr)[i].end_time);
        (*arr)[i].start_time = lower - rank.begin() + 1;
        (*arr)[i].end_time = lower2 - rank.begin() + 1;
    }
}

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i].start_time >> arr[i].end_time >> arr[i].reward;

    coordinate_compress(&arr);
    
    int maximum_time = -1e9;
    for (int i = 0; i < n; i++)
    {
        maximum_time = max(maximum_time, arr[i].end_time);
    }
    
    v2i dp(n + 1, vi(maximum_time + 1));        
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maximum_time; j++)
        {
            if (j < arr[i-1].end_time) 
            {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max(dp[i][arr[i-1].start_time - 1] + arr[i-1].reward, dp[i-1][j]);
        }
    }
    
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= maximum_time; j++)
    //     {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }
    
    cout << dp[n][maximum_time] << '\n';
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
