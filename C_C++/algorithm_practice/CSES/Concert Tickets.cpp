#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
multiset<int> ms;
vector<int> arr;

void solve()
{
    cin >> n >> m;
    arr.resize(m);

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ms.insert(tmp);
    }

    for (auto i : arr)
    {
        cin >> i;
    }

    for (auto i : arr)
    {
        auto it = ms.upper_bound(i);
        if (it == ms.begin())
        {
            cout << -1 << '\n';
            continue;
        }

        it = prev(it);

        cout << (*it) << '\n';
        ms.erase(it);
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