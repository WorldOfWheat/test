#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> arr;
vector<int> arr2;

void solve()
{
    cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        auto upper = upper_bound(arr2.begin(), arr2.end(), arr[i]);
        if (upper == arr2.end()) arr2.push_back(arr[i]);
        else 
        {
            *upper = arr[i];
        }
    }

    cout << (arr2.size()) << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}