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
    if (x.left < y.left) return true;
    if (x.left == y.left && x.right >= y.right) return true;

    return false;
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

    int maxi_right = arr.front().right;
    for (int i = 1; i < n; i++)
    {
        seg current = arr[i];
        record[current.index].first = maxi_right >= current.right;
        maxi_right = max(maxi_right, current.right);
    }

    int mini_right = arr.back().right;
    for (int i = n - 1 - 1; i >= 0; i--)
    {
        seg current = arr[i];
        record[current.index].second = current.right >= mini_right;
        mini_right = min(current.right, mini_right);
    }
    for (int i = 0; i < n; i++) cout << record[i].second << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << record[i].first << ' ';
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
