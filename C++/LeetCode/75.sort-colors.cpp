#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3);
        for (auto i : nums)
        {
            colors[i]++;
        }
        int index = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (counter == colors[index])
            {
                index++;
                counter = 0;
            }
            nums[i] = index;
            counter++;
        }
    }
};
// @lc code=end

