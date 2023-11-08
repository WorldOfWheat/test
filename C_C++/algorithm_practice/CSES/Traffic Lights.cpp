#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
set<int> se;
multiset<int> ms;

void solve()
{
    cin >> n >> m;

    se.insert(0);
    se.insert(n);
    ms.insert(n);

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;

        int r = *(se.upper_bound(a));
        int l = *(prev(se.lower_bound(a)));

        ms.erase(ms.lower_bound(r - l));
        ms.insert(r - a);
        ms.insert(a - l);
        se.insert(a);

        cout << (*(ms.rbegin())) << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}