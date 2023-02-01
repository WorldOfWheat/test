from bisect import bisect_left
#
# @lc app=leetcode id=18 lang=python
#
# [18] 4Sum
#

# @lc code=start
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
# [0,0,0,0]\n0
# [0,0,0,0]
# 0
        nums = sorted(nums)
        length = len(nums) - 1
        result = []
        for ptrL in range(length - 2):
            for ptrR in range(ptrL + 1, length - 1):
                ptrL2 = ptrR + 1
                ptrR2 = length
                while (ptrL2 < ptrR2):
                    sum = nums[ptrL] + nums[ptrR] + nums[ptrL2] + nums[ptrR2]
                    if sum == target:
                        result.append([nums[ptrL], nums[ptrR], nums[ptrL2], nums[ptrR2]])
                        ptrL2 += 1
                        ptrR2 -= 1
                    else:
                        if sum > target:
                            ptrR2 -= 1
                        elif sum < target:
                            ptrL2 += 1
        result = sorted(result)
        result2 = []
        for i in range(len(result)):
            index = bisect_left(result, result[i], i + 1)
            if index == len(result) or result[i] != result[index]:
                result2.append(result[i])
        return result2       

# @lc code=end

