#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> dp;

int cal(int x)
{
    // cerr << x << '\n';
    if (x <= 9) return 1;
    if (dp[x] != 0) return dp[x];
    
    int lsb = x;
    int minimum = 1e9;
    while (lsb > 0)
    {
        int sub_num = lsb % 10;
        if (sub_num != 0) minimum = min(cal(x - sub_num), minimum);
        lsb /= 10;
    }
    
    return dp[x] = minimum + 1;
}

void solve()
{
    cin >> n;   

    dp.resize(n + 1);
    
    cout << cal(n) << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}