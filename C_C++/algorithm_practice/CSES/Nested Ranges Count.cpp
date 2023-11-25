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
vector<int> BIT;

void update(int pos, int value)
{
    int index = pos;
    int size = BIT.size();

    while (index <= size)
    {
        BIT[index] += value;
        index += -index & index;
    }
}

int query(int pos)
{
    int index = pos;
    int sum = 0;
    while (index > 0)
    {
        sum += BIT[index];
        index -= -index & index;
    }
    return sum;
}

void coord_compress(vector<seg> &arr)
{
    vector<int> digits;
    for (auto i : arr) 
    {
        digits.emplace_back(i.left);
        digits.emplace_back(i.right);
    }

    sort(begin(digits), end(digits));
    digits.erase(unique(begin(digits), end(digits)), end(digits));
    
    int size = arr.size();
    for (int i = 0 ; i < size; i++)
    {
        seg &current = arr[i];
        int rank_1 = lower_bound(begin(digits), end(digits), current.left) - begin(digits);
        int rank_2 = lower_bound(begin(digits), end(digits), current.right) - begin(digits);
        current.left = rank_1;
        current.right = rank_2;
    }
}

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
    BIT.resize(1e6 + 1, 0);

    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i].left >> arr[i].right;
        arr[i].index = i;
    }
    
    coord_compress(arr);
    sort(arr.begin(), arr.end(), compare);
    
    for (int i = 0; i < n; i++)
    {
        seg current = arr[i];
        int count = query(1e6 + 1) - query(current.right);
        record[current.index].second = count;
        update(current.right + 1, 1);
    }
    
    BIT.clear();
    BIT.resize(1e6 + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        seg current = arr[i];
        int count = query(current.right + 1);
        record[current.index].first = count;
        update(current.right + 1, 1);
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
