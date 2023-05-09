struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
class Solution {
public:
    bool dfs(TreeNode* current, int sum, int target)
    {
        if (!(current->left || current->right))
        {
            return (sum + current->val) == target;
        }

        bool result = false; 
        if (current->left)
        {
            result |= dfs(current->left, sum + current->val, target);
        }
        if (current->right)
        {
            result |= dfs(current->right, sum + current->val, target);
        }
        return result;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
        {
            return false;
        }

        bool result = false; 
        if (root->left)
        {
            result |= dfs(root->left, root->val, targetSum);
        }
        if (root->right)
        {
            result |= dfs(root->right, root->val, targetSum);
        }
        if (!(root->left || root->right))
        {
            result |= root->val == targetSum;
        }
        return result;
    }
};
// @lc code=end

