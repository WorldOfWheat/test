from bisect import bisect_left
from bisect import bisect
from random import randrange

def main():
    nums = [[1, 1], [1, 1], [1, 1], [1, 1], [1, 2]]
    for i in range(5):
        nums.append([randrange(1, 9), randrange(1, 9)])
    nums = sorted(nums)
    print(nums)
    for i in range(len(nums)):
        index = bisect_left(nums, nums[i], i + 1)
        if index == len(nums) or nums[index] != nums[i]:
            print(nums[i])

if __name__ == '__main__':
    main()
