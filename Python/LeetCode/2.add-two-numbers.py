#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode(0)
        node = result
        num = 0
        while (l1 is not None) or (l2 is not None) or num > 0:
            if l1 is not None:
                num += l1.val
                l1 = l1.next
            if l2 is not None:
                num += l2.val
                l2 = l2.next

            node.next = ListNode(num % 10)
            node = node.next

            num = num // 10

        return result.next
        
# @lc code=end

