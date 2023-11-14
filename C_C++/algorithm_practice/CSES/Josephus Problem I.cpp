#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
list<int> li;

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++) li.push_back(i);

    while (li.size() != 1)
    {
        int front = li.front();
        li.pop_front();
        li.push_back(front);
        front = li.front();
        cout << front << ' ';
        li.pop_front();
    }

    cout << li.front() << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
