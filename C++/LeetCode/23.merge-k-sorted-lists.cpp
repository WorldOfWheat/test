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
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
// Definition for singly-linked list.

class Solution {

private:
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* result;
        if (list1->val < list2->val)
        {
            result = list1;
        }
        else
        {
            result = list2;
        }

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val >= list2->val)
            {
                result->next = list2;
                list2 = list2->next;
            }
            else
            {
                result->next = list1;
                list1 = list1->next;
            }
            result = result->next;
        }
        while (list1 != NULL)
        {
            result->next = list1; 
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            result->next = list2; 
            list2 = list2->next;
        }

        return result;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists[0], lists[1]);
    }
};
// @lc code=end

