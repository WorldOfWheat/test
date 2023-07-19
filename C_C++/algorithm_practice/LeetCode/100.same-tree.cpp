#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
class Solution {
private:
    string path_p;
    string path_q;
    void dfs(TreeNode* root, string &path)
    {
        if (root == nullptr)
        {
            path += "null";
            return;
        }
        path += root->val + '0'; 

        dfs(root->left, path);
        dfs(root->right, path);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, path_p);
        dfs(q, path_q);

        return path_p == path_q;
    }
};
// @lc code=end

