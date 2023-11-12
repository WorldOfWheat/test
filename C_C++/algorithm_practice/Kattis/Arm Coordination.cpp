#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int k;

void solve()
{
    cin >> n >> m >> k;
    cout << n - k << ' ' << m + k << '\n';
    cout << n + k << ' ' << m + k << '\n';
    cout << n + k << ' ' << m - k << '\n';
    cout << n - k << ' ' << m - k << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}