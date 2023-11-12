#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> arr;
vector<int> prefix;

int binary_search(int goal, int start, vector<int> arr)
{
    int l = 0, r = arr.size();
    while (l < r)
    {
        int mid = (l + r) >> 1;

        int sum = prefix[mid] - prefix[start];
        if (sum < goal) l = mid + 1;
        else r = mid;
    }

    return l;
}

void solve()
{
    int n, m; 
    
    cin >> n >> m;

    arr.resize(n);
    prefix.resize(n + 1);

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + arr[i-1];

    for (int i = 0; i < n; i++)
    {
        int right = binary_search(m, i, prefix);
        if (prefix[right] - prefix[i] == m)
        {
            for (int j = i + 1; j <= right; j++) cout << j << ' ';
            cout << '\n';
        }
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