#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
private:
    vector<int> nums;
    bitset<6> used;
    vector<vector<int>> result;
    void allPermute(vector<int> current, int counter)
    {
        if (counter == nums.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }

            current.push_back(nums[i]);
            used[i] = 1;
            allPermute(current, counter + 1);
            current.pop_back();
            used[i] = 0;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;

        vector<int> temp;
        allPermute(temp, 0);

        return result;
    }
};
// @lc code=end

