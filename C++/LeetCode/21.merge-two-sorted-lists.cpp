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
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }

        ListNode* result = NULL;
        if (list1->val < list2->val)
        {
            result = list1;
            list1 = list1->next;
        }
        else
        {
            result = list2;
            list2 = list2->next;
        }

        ListNode* ptr = result;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                ptr->next = list1;
                list1 = list1->next;
            }
            else
            {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }

        if (list1 == NULL)
        {
            ptr->next = list2;
        }
        if (list2 == NULL)
        {
            ptr->next = list1;
        }

        return result;
    }
};
// @lc code=end

