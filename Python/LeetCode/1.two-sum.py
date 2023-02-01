#
# @lc app=leetcode id=1 lang=python
#
# [1] Two Sum
#

# @lc code=start
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums = list(nums)
        for i in range(len(nums)):
            nums[i] = (nums[i], i)
        nums.sort()
        ptrL = 0
        ptrR = len(nums) - 1
        sum = 0
        while ptrL < ptrR:
            sum = nums[ptrL][0] + nums[ptrR][0]
            if sum > target:
                ptrR -= 1
            elif sum < target:
                ptrL += 1
            else:
                result = []
                result.append(nums[ptrL][1])
                result.append(nums[ptrR][1])
                return result

# @lc code=end
