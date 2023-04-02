#include <bits/stdc++.h>

using namespace std;

// @leetCode: enable
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> copy_nums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            copy_nums[i] = {nums[i], i};
        }
        
        sort(copy_nums.begin(), copy_nums.end());

        int ptrL = 0;
        int ptrR = copy_nums.size() - 1;
        while (ptrL <= ptrR) {
            int sum = copy_nums[ptrL].first + copy_nums[ptrR].first;
            if (sum == target) {
                vector<int> res = {copy_nums[ptrL].second, copy_nums[ptrR].second};
                return res;
            }
            if (sum < target) {
                ptrL++;
                continue;
            }
            ptrR--;
        }
        
        vector<int> res = {copy_nums[ptrL].second, copy_nums[ptrR].second};
        return res;
    }
};
// @lc code=end

