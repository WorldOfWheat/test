#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int value;
    ListNode* next;

    ListNode() 
    {
        next = NULL;
    };
    ListNode(int x)
    {
        this->value = x;
        next = NULL;
    }
};

void solve() 
{
    ListNode* start = new ListNode(0);
    ListNode* current = start;
    for (int i = 1; i <= 10; i++)
    {
        current->next = new ListNode(i);
        current = current->next;
    }
    current->next = start;

    while (start != NULL)
    {
        cout << (start->value) << ' ';
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