#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
map<int, int> ma;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ma[a] += 1;
        ma[b] -= 1;
    }

    int now = 0;
    int ans = 0;
    for (auto i : ma)
    {
        now += i.second;
        ans = max(ans, now);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}