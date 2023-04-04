#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

        int size = merged.size();
        if (((int) size) % 2 == 0) {
            size /= 2;
            double result = ((double) merged[size - 1] + (double) merged[size]) / 2.0;
            return result;
        }
        return merged[size / 2];
    }
};
// @lc code=end
