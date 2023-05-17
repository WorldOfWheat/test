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
        int size = 0;
        ListNode* start = head;
        ListNode* current = start;
        while (current->next != NULL)
        {
            current = current->next;
            size++;
        }
        k %= size;

        ListNode* newStart = head;
        for (int i = 0; i < size - k; i++)
        {
            newStart = newStart->next;
        }

        return current;
    }
};
// @lc code=end

