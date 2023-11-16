#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
set<int> se;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) se.insert(i);

    auto it = se.begin();
    while (se.size())
    {
        // for (auto i : se) cerr << i << ' ';
        // cerr << '\n';
        int offset = distance(se.begin(), it);
        offset = (offset + m) % se.size();
        it = next(se.begin(), offset);
        auto it_next = next(it);
        cout << (*it) << ' ';
        se.erase(it);
        it = it_next;
    }
    cout << '\n';
    // cerr << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}