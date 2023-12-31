#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug_container(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
int n;
vector<string> graph;
vector<vector<int>> dp;

void solve()
{
    cin >> n;
    
    graph.resize(n);
    for (int i = 0; i < n; i++) cin >> graph[i];
    
    if (graph[0][0] == '*')
    {
        cout << "0\n";
        return;
    }
    
    dp.resize(n + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (i == 1 && j == 1) continue;
            if (graph[i-1][j-1] == '*')
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    
    cout << dp[n][n] << "\n";
}

int main()
{
    fastio;

    solve();

    return 0;
}