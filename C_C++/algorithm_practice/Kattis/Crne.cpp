#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll n;

void solve()
{
    cin >> n;

    cout << ((n / 2) + 1)  * ((n / 2 + n % 2) + 1) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}