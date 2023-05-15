#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
        {
            return vector<int>();
        }

        int size_x = matrix.size();
        int size_y = matrix[0].size();
        int u, d, l, r;
        u = 0, l = 0, d = size_x - 1, r = size_y - 1;

        vector<int> result;
        while (result.size() < size_x * size_y)
        {
            for (int i = l; i <= r; i++)
            {
                result.push_back(matrix[u][i]);
            }
            u++;
            for (int i = u; i <= d; i++)
            {
                result.push_back(matrix[i][r]);
            }
            r--;
            if (u <= d)
            {
                for (int i = r; i >= l; i--)
                {
                    result.push_back(matrix[d][i]);
                }
                d--;
            }
            if (l <= r)
            {
                for (int i = d; i >= u; i--)
                {
                    result.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        return result;
    }
};
// @lc code=end

