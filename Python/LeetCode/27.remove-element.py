#
# @lc app=leetcode id=27 lang=python
#
# [27] Remove Element
#

# @lc code=start
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """

        result = []
        for i in nums:
            if i != val:
                result.append(i)
        for i in range(len(result)):
            nums[i] = result[i]
        
        return len(result)
        
# @lc code=end

