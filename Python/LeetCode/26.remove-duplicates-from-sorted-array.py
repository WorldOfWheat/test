from bisect import bisect_left

#
# @lc app=leetcode id=26 lang=python
#
# [26] Remove Duplicates from Sorted Array
#

# @lc code=start
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        unique = list(dict.fromkeys(nums))
        unique = sorted(unique)
        for i in range(len(unique)):
            nums[i] = unique[i]

        return len(unique)
        
# @lc code=end

