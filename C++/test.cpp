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

void threeNPlusOne(int start)
{
    cout << start << ' ';
    if (start == 1)
    {
        return;
    }

    if (start % 2 == 0)
    {
        threeNPlusOne(start / 2);
    }
    else
    {
        threeNPlusOne(start * 3 + 1);
    }
}

void solve() 
{
    threeNPlusOne(19);
    // ListNode* start = new ListNode(0);
    // ListNode* current = start;
    // for (int i = 1; i <= 10; i++)
    // {
    //     current->next = new ListNode(i);
    //     current = current->next;
    // }
    // current->next = start;

    // while (start != NULL)
    // {
    //     cout << (start->value) << ' ';
    //     start = start->next;
    // }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}