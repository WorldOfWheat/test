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
set<int> se;

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
        seg current = arr[i];
        auto lower = se.lower_bound(current.right);
        if (lower != se.end()) 
        {
            int count = distance(lower, se.end());
            record[current.index].second = count;
        }
        se.insert(current.right);
    }

    se.clear();

    for (int i = n - 1; i >= 0; i--)
    {
        seg current = arr[i];

        auto upper = se.upper_bound(current.right);
        if (upper != se.begin())
        {
            upper--;
            int count = distance(se.begin(), upper) + 1;
            record[current.index].first = count;
        }
        se.insert(current.right);
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
