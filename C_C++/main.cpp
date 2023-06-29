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
#define nl '\n';
#define INF (int) 1e18
#define MOD (int) 1e9 + 7

using namespace std;

class NodeData
{
public:
    static NodeData combine(NodeData a, NodeData b)
    {
        NodeData combined;
        combined.sum = a.sum + b.sum;
    }
    int sum;
};

class TreeNode
{
public:
    TreeNode()
    {
        left = NULL;
        right = NULL;
    }

    TreeNode* left;
    TreeNode* right;
    NodeData data;
};

class SegmentTree
{
public:
    void build(vector<int> &arr)
    {
        size = arr.size();
        build(arr, root, 0, size);
    }
    NodeData query(int index)
    {
        return query(root, index, index + 1, 0, size);
    }
    NodeData query(int index_left, int index_right)
    {
        return query(root, index_left, index_right, 0, size);
    }

private:
    int size;
    TreeNode* root = new TreeNode();
    NodeData build(V arr, TreeNode* node, int left, int right)
    {
        if (left + 1 == right)
        {
            node->data.sum = arr[left];
            return node->data;
        }
        int mid = (left + right) >> 1;
        node->left = new TreeNode();
        node->right = new TreeNode();
        NodeData left_data = build(arr, node->left, left, mid);
        NodeData right_data = build(arr, node->right, mid, right);
        NodeData combined = NodeData::combine(left_data, right_data);
        node->data = combined;
        return combined;
    }
    NodeData query(TreeNode* node, int index_left, int index_right, int left, int right)
    {
        if (index_left == left && index_right == right)
        {
            return node->data;
        }

        int mid = (left + right) >> 1;
        if (index_right <= mid)
        {
            return query(node->left, index_left, index_right, left, mid);
        }
        if (index_left >= mid)
        {
            return query(node->right, index_left, index_right, mid, right);
        }

        NodeData left_data = query(node->left, index_left, mid, left, mid);
        NodeData right_data = query(node->right, mid, index_right, mid, right);
        NodeData combined = NodeData::combine(left_data, right_data);
        return combined;
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
    arr = {1, 2, 3, 4, 5, 6};
    SegmentTree seg;
    seg.build(arr);
    cout << seg.query(1, 4).sum << nl;

    // cin >> n >> m;
    // arr.resize(n);
    // for (auto &i : arr)
    // {
    //     cin >> i;
    // }

    // discrete(arr);

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}