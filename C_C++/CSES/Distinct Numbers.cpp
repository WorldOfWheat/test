#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

void solve()
{
    cin >> n;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i;
    }

    sort(arr.begin(), arr.end());
    arr.erase(
        unique(arr.begin(), arr.end()),
        arr.end()
    );

    cout << (arr.size()) << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}