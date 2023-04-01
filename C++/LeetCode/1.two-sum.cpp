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
        sort(nums.begin(), nums.end());

        int ptrL = 0;
        int ptrR = nums.size() - 1;
        while (ptrL <= ptrR) {
            int sum = nums[ptrL] + nums[ptrR];
            if (sum == target) {
                vector<int> res = {ptrL, ptrR};
                return res;
            }
            if (sum < target) {
                ptrL++;
                continue;
            }
            ptrR--;
        }
        
        vector<int> res = {ptrL, ptrR};
        return res;
    }
};
// @lc code=end

