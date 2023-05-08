#include <bits/stdc++.h>

using namespace std;

vector<int> arr(5, 0);

void test(int l, int r)
{
    if (l + 1 == r)
    {
        cout << l << ' ' << r << '\n';
        return;
    }

    int mid = (l + r) >> 1;
    test(l, mid);
    test(mid, r);
}

void printArr(int i)
{
    cout << i << '\n';
}

void solve() 
{
    iota(arr.begin(), arr.end(), 1);
    for_each(arr.begin(), arr.end(), printArr);
    test(0, 5);
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}