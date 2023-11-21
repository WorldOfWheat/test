#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct seg {
    int left;
    int right;
    int index;
};

int n;
vector<seg> arr;
vector<pii> record;

bool compare(seg x, seg y)
{
    int distance_x = x.right - x.left;
    int distance_y = y.right - y.left;
    if (distance_x < distance_y) return false;

    return true;
}

void solve()
{
    cin >> n;

    arr.resize(n);
    record.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i].left >> arr[i].right;
        arr[i].index = i;
    }
    
    sort(arr.begin(), arr.end(), compare);

    // for (int i = 0; i < n; i++)
    // {
    //     cerr << arr[i].left << ' ' << arr[i].right << '\n';
    // }

    int maximum_end = -1e9;
    for (int i = 0; i < n; i++)
    {
        seg current = arr[i];
        if (current.right < maximum_end) record[current.index].second = 1;
        maximum_end = max(maximum_end, current.right);
    }

    int minimum_end = 1e9;
    for (int i = n - 1; i >= 0; i--)
    {
        seg current = arr[i];
        if (minimum_end < current.right) record[current.index].first = 1;
        minimum_end = min(minimum_end, current.right);
    }
    for (int i = 0; i < n; i++) cout << record[i].first << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << record[i].second << ' ';
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
