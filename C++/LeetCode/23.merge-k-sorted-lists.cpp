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
    vector<ListNode*> lists;
    ListNode* result = new ListNode(0);

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }

        ListNode* result = new ListNode(0);
        ListNode* start = result;
        if (list1->val < list2->val)
        {
            result->val = list1->val;
            list1 = list1->next;
        }
        else
        {
            result->val = list2->val;
            list2 = list2->next;
        }
        
        while (list1 != NULL && list2 != NULL)
        {
            result->next = new ListNode(0);
            result = result->next;
            if (list1->val >= list2->val)
            {
                result->val = list2->val;
                list2 = list2->next;
            }
            else
            {
                result->val = list1->val;
                list1 = list1->next;
            }
        }
        if (list1 != NULL)
        {
            result->next = list1;
        }
        if (list2 != NULL)
        {
            result->next = list2;
        }
        // while (list1 != NULL)
        // {
        //     result->next = new ListNode(0);
        //     result = result->next;
        //     result->val = list1->val; 
        //     list1 = list1->next;
        // }
        // while (list2 != NULL)
        // {
        //     result->next = new ListNode(0);
        //     result = result->next;
        //     result->val = list2->val; 
        //     list2 = list2->next;
        // }

        return start;
    }

    ListNode* mergeAll(int l, int r)
    {
        if (l + 1 >= r)
        {
            return lists[l];
        }

        int mid = (l + r) >> 1;
        ListNode* resultL = mergeAll(l, mid);
        ListNode* resultR = mergeAll(mid, r);

        return merge(resultL, resultR);
    }   
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return NULL;
        }
        if (lists.size() <= 1)
        {
            return lists[0];
        }

        this->lists = lists;

        return mergeAll(0, lists.size());
    }
};
// @lc code=end

