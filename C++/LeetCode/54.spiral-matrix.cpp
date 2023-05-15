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
        int size_x = matrix.size();
        int size_y = matrix[0].size();
        int index = 0;
        int counter = 1;
        vector<int> result;
        while (counter < size_x * size_y)
        {
            for (int i = index; i < size_y - index - 1; i++)
            {
                result.push_back(matrix[index][i]);
                counter++;
            }
            for (int i = index; i < size_x - 1; i++)
            {
                result.push_back(matrix[i][size_y - index - 1]);
                counter++;
            }
            for (int i = size_y - 1 - index; i >= index + 1; i--)
            {
                result.push_back(matrix[size_x - index - 1][i]);
                counter++;
            }
            for (int i = size_x - index - 1; i >= index + 1; i--)
            {
                result.push_back(matrix[i][size_x - index - 1]);
                counter++;
            }
            index++;
        }

        return result;
    }
};
// @lc code=end

