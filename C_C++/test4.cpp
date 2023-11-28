#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, m;
vector<ll> dp;
vector<ll> record;

void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        dp.resize(m + 1);
        record.resize(m + 1);

        dp[0] = n;
        record[0] = n;
        for (int i = 1; i <= m; i++)
        {
            dp[i] = dp[i-1] + (dp[i-1] / 2 * 3);
            record[i] = dp[i] - dp[i-1];
            if (i >= 3) dp[i] -= record[i-3];
        }
        
        cout << dp[m] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}