#
# @lc app=leetcode id=16 lang=python
#
# [16] 3Sum Closest
#

# @lc code=start
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
#[-1,2,1,-4]
#1
#[-4,-1,1,2]
        nums = sorted(nums)
        minimum = 1e9
        result = 0
        for ptrL2 in range(0, len(nums) - 1):
            ptrL = ptrL2 + 1
            ptrR = len(nums) - 1
            while (ptrL < ptrR):
                sum = nums[ptrL] + nums[ptrL2] + nums[ptrR]
                diff = abs(target - sum)
                if diff < minimum:
                    minimum = diff
                    result = sum
                if sum > target:
                    ptrR -= 1
                else:
                    ptrL += 1
        return result
        
# @lc code=end

