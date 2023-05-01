#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, result.begin());
        nums1 = result;
    }
};
// @lc code=end

