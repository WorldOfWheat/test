#include <bits/stdc++.h>
#define int long long
#define VS vector<string>
#define V vector<int>
#define VV vector<V>
#define VP vector<PII>
#define VVP vector<VP>
#define PII pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define INF (int) 1e18

using namespace std;

class TreeNode
{
public:
    TreeNode()
    {
        Left = NULL;
        Right = NULL;
        value = 0;
    }
    TreeNode* Left;
    TreeNode* Right;
    int value;
};

class SegmentTree
{
public:
    void build(vector<int> &arr)
    {
        build(arr, 0, arr.size());
    }
private:
    TreeNode* root;
    void add(vector<int> &arr, int left, int right, int index)
    {
        int mid = (left + right) >> 1;
        if (index < mid)
        {
            
        }
    }
};

int n, m;
V arr;
VP arr2;

void discrete(V &arr)
{
    V arr_copy(arr);
    sort(arr_copy.begin(), arr_copy.end());
    arr_copy.erase(unique(arr_copy.begin(), arr_copy.end()), arr_copy.end());
    for (auto &i : arr)
    {
        auto lower = lower_bound(arr_copy.begin(), arr_copy.end(), i);
        i = distance(arr_copy.begin(), lower) + 1;
    }
}

void solve()
{
    cin >> n >> m;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i;
    }

    discrete(arr);

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}