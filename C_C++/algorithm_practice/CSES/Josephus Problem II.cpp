#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> arr;

void update(int pos, int size, int value)
{
    while (pos <= size)
    {
        arr[pos] += value;
        pos += pos & -pos;
    }
}

int query(int pos, int size)
{
    int res = 0;
    while (pos > 0)
    {
        res += arr[pos];
        pos -= pos & -pos;
    }

    return res;
}

int binary_search(int l, int r, int goal)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (query(mid, r) > goal) r = mid; 
        else l = mid + 1;
    }

    return l;
}

void solve()
{
    cin >> n >> m;

    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) update(i, n, 1);

    int last = 0;
    for (int i = 0; i < n; i++)
    {
        int count_down = n - i;
        int goal = (last + (m % count_down)) % count_down;
        int index;

        index = binary_search(1, n + 1, goal);

        cout << index << ' ';

        last = goal;
        update(index, n, -1);
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}