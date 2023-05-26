#include <bits/stdc++.h>

using namespace std;

bool is_power_of_2(int n)
{
    return !(n & (n - 1));
}

void solve() 
{
    int n;
    while (cin >> n)
    {
        cout << (is_power_of_2(n)) << endl;
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}