#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
private:
    vector<int> prefixSum;
    vector<int> suffixSum;

public:
    int maxSub(int l, int r)
    {
        int mid = (l + r) >> 1;
    }
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        prefixSum.resize(size + 1);
        suffixSum.resize(size + 1);
        for (int i = 0; i < size; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            suffixSum[i + 1] = suffixSum[i] + nums[size - 1 - i];
        }

        return maxSub(0, size);
    }
};
// @lc code=end

