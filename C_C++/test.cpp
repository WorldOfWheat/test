#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Node {
public:
    int value;
    Node* next;
};

int n;

void solve()
{
    cin >> n;
    Node* head = new Node();
    Node* current = head;
    for (int i = 1; i <= n; i++)
    {
        current->value = i;
        current->next = new Node();
        current = current->next;
    }
    current->next = head;
    current = head;
    while (current != nullptr)
    {
        cout << current->next->value << ' ';
        current->next = current->next->next;
        current = current->next;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
