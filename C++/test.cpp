#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> arr;

void solve() 
{
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int ptrL = j + 1;
            int ptrR = n - 1;
            while (ptrL < ptrR)
            {
                int sum = arr[i].first + arr[j].first + arr[ptrL].first + arr[ptrR].first;
                if (sum == m)
                {
                    cout << i+1 << ' ' << j+1 << ' ' << ptrL+1 << ' ' << ptrR+1 << '\n';
                    return;
                }
                if (sum > m)
                {
                    ptrR--;
                    continue;
                }
                ptrL++;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}