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
    vector<int> nums;
    // vector<int> prefixSum;
    // vector<int> suffixSum;

public:
    int crossSum(int l, int r)
    {
        int mid = (l + r) >> 1;
        int sum = 0;
        int result1 = INT_MIN;
        int result2 = INT_MIN;
        for (int i = mid - 1; i >= l; i--)
        {
            sum += nums[i];
            result1 = max(result1, sum);
        }
        sum = 0;
        for (int i = mid; i < r; i++)
        {
            sum += nums[i];
            result2 = max(result2, sum);
        }

        return max({result1, result2, result1 + result2});
    }
    
    int maxSub(int l, int r)
    {
        if (l + 1 == r)
        {
            return nums[l];
        }

        int mid = (l + r) >> 1;
        int sum1 = maxSub(l, mid);
        int sum2 = maxSub(mid, r);
        int result;
        result = max({sum1, sum2, crossSum(l, r)});

        return result;
    }

    int maxSubArray(vector<int>& nums) {
        this->nums = nums;
        int size = nums.size();

        return maxSub(0, size);
    }
};
// @lc code=end

