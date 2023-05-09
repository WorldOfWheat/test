#include <bits/stdc++.h>

using namespace std;

void solve() 
{
    vector<int> nums(5);
    iota(nums.begin(), nums.end(), 0);
    for_each(nums.begin(), nums.end(), [](int x) {
        cout << x << '\n';
    });
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}