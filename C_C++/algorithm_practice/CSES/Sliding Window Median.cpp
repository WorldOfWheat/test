#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;
vector<int> BIT_tree;
queue<int> qu;
map<int, int> ma;

void update(int pos, int value) 
{
    while (pos <= n) 
    {
        BIT_tree[pos] += value;
        pos += pos & -pos;
    }
}

int query(int pos) 
{
    int result = 0;
    while (pos > 0) 
    {
        result += BIT_tree[pos];
        pos -= pos & -pos;
    }
    return result;
}

int get_median() 
{
    const int kth = ceil((double) m / 2);
    int l = 1, r = n + 1;
    while (l < r) 
    {
        int mid = (l + r) >> 1;
        if (query(mid) >= kth) r = mid;
        else l = mid + 1;
    }
    return l;
}

void coordinate_compress(vector<int> &arr)
{
    vector<int> index_mapping = arr;
    sort(index_mapping.begin(), index_mapping.end());
    index_mapping.erase(unique(index_mapping.begin(), index_mapping.end()), index_mapping.end());
    
    for (int i = 0; i < n; i++)
    {
        int new_value = lower_bound(index_mapping.begin(), index_mapping.end(), arr[i]) - index_mapping.begin();
        new_value++;
        ma[new_value] = arr[i];
        arr[i] = new_value;
    }
}

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    BIT_tree.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> arr[i];

    coordinate_compress(arr);
    
    for (int i = 0; i < m; i++)
    {
        qu.push(arr[i]);
        update(arr[i], 1);
    }

    cout << ma[get_median()] << ' ';
    
    for (int i = m; i < n; i++) 
    {
        int front = qu.front();
        qu.pop();
        qu.push(arr[i]);
        update(front, -1);
        update(arr[i], 1);
        cout << ma[get_median()] << ' ';
    }   
    cout << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}