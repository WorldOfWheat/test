#include <bits/stdc++.h>

using namespace std;


void solve() 
{
    bitset<5> bs;
    bs[0] = 1;
    cout << (bs[0]) << '\n';
    bs.reset();
    cout << (bs[0]) << '\n';
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}