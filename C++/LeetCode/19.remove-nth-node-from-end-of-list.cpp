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
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptrL = head;
        ListNode* ptrR = head;

        if (ptrL == NULL)
        {
            return NULL;
        }
        while (n--)
        {
            ptrR = ptrR->next;
            if (ptrR == NULL)
            {
                return ptrL->next;
            }
        }
        while (ptrR->next != NULL)
        {
            ptrL = ptrL->next;
            ptrR = ptrR->next;
        }
        ptrL->next = ptrL->next->next;

        return head;
    }
};
// @lc code=end

