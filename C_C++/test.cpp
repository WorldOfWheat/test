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
    if (x.left > y.left) return false;
    if (x.left < y.left) return true;

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

    for (int i = 0; i < n; i++)
    {
        cerr << arr[i].left << ' ' << arr[i].right << '\n';
    }

    for (int i = 0; i < n - 1; i++)
    {
        seg &current = arr[i];
        seg &next = arr[i + 1];
        if (current.left <= next.left && current.right >= next.right)
        {
            record[current.index].first = 1;
            record[next.index].second = 1;
        }
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
