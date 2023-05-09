#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int counter = size - 1;
        int index = 0;
        for (int i = 0; i < size >> 1; i++)
        {
            for (int j = 0; j < counter; j++)
            {
                int temp = matrix[index][index];
                for (int o = index + 1; o < size - index; o++)
                {
                    swap(temp, matrix[index][o]);
                }
                for (int o = index + 1; o < size - index; o++)
                {
                    swap(temp, matrix[o][size - index - 1]);
                }
                for (int o = size - 1 - index - 1; o >= index; o--)
                {
                    swap(temp, matrix[size - index - 1][o]);
                }
                for (int o = size - 1 - index - 1; o >= index; o--)
                {
                    swap(temp, matrix[o][index]);
                }
            }
            index++;
            counter -= 2;
        }
    }
};
// @lc code=end

