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
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = NULL;

        while (list1 != NULL/* && list2 != NULL*/)
        {
            result = new ListNode;
            result->val = list1->val;
            list1 = list1->next;
            // if (list1->val < list2->val)
            // {
            //     result->val = list1->val;
            //     list1 = list1->next;
            // }
            // else
            // {
            //     result->val = list2->val;
            //     list2 = list2->next;
            // }
            result = result->next;
        }

        return result;
    }
};
// @lc code=end

