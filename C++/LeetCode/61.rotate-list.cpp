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
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        int size = 1;
        ListNode* start = head;
        ListNode* current = start;
        while (current->next != NULL)
        {
            current = current->next;
            size++;
        }
        if (size == 1)
        {
            return head;
        }

        current->next = start;

        ListNode* newStart = start;
        for (int i = 0; i < size - (k % size); i++)
        {
            newStart = newStart->next;
        }
        while (current->next != newStart)
        {
            current = current->next;
        }
        current->next = nullptr;
        
        return newStart;
    }
};
// @lc code=end

