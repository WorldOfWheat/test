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
        if (!(head && head->next))
        {
            return head;
        }

        ListNode* start = new ListNode();
        ListNode* last = start;
        ListNode* now = head;
        while (now && now->next)
        {
            last->next = now->next;
            now->next = last->next->next;
            last->next->next = now;

            last = now;
            now = now->next;
        }

        return start->next;
    }
};
// @lc code=end

