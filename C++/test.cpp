#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void solve() 
{
    ListNode* start = new ListNode(0);
    ListNode* current = start;
    for (int i = 1; i <= 5; i++)
    {
        current->next = new ListNode(i);
        current = current->next;
    }
    current->next = start;

    while (start != NULL)
    {
        cout << (start->val) << ' ';
        start = start->next;
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}