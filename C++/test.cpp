#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct person 
{
    int age;
    char* name;
    person() : age(0), name(NULL) {}
    person(int x) : age(x), name(NULL) {}
    person(int x, char* y) : age(x), name(y) {}
};

void solve() 
{
    ListNode* node = new ListNode(0);
    cout << (node->val) << '\n';
    person a = new person(5);

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}