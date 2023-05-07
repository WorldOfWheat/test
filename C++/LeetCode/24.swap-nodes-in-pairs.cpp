#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        ListNode* result = head->next;

        while (ptr != NULL)
        {
            ListNode* next = ptr->next->next;
            ptr->next->next = ptr;
            ptr->next = next;
            ptr = ptr->next->next;
        }

        return result;
    }
};
// @lc code=end

