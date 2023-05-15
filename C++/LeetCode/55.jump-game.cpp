#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            counter--;
            counter = max(counter, nums[i]);
            if (i != nums.size() - 1 && counter == 0)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

