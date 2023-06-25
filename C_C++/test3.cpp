#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i.first;
        cin >> i.second;
    }

    sort(arr.begin(), arr.end());

    cout << '\n';
    for (auto i : arr) 
    {
        cout << i.first << " " << i.second << '\n';
    }

    int last = 0;
    for (int i = 0; i < n; i++)
    {
        
    }

    return 0;
}