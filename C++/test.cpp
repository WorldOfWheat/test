#include <bits/stdc++.h>

using namespace std;

struct Data
{
    int sum;
};
struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    Data data;
    TreeNode() : left(nullptr), right(nullptr), data() {};
};

Data generate(vector<int> arr, TreeNode* &node, int l, int r)
{
    cout << "a\n";
    if (node == nullptr)
    {
        node = new TreeNode();
    }
    if (l + 1 >= r)
    {
        node->data.sum = arr[l];
        return node->data;
    }
    int mid = (l + r) >> 1;
    Data left = generate(arr, node->left, l, mid);
    Data right = generate(arr, node->right, mid, r);

    node->data.sum = left.sum + right.sum;
    return node->data;
}

int query(int index, TreeNode* &node, int l, int r)
{
    if (l + 1 >= r)
    {
        return node->data.sum;
    }

    int mid = (l + r) >> 1;
    if (index < mid)
    {
        return query(index, node->left, l, mid);
    }
    if (index < r)
    {
        return query(index, node->right, mid, r);
    }
}

void solve() 
{
    vector<int> arr(20);
    iota(arr.begin(), arr.end(), 1);
    TreeNode* root;
    generate(arr, root, 0, arr.size());

    cout << "OK\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}