#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;

int n, m;

void solve()
{
    cin >> n >> m;

    cout << n / m << '.';
    n = n % m;
    n *= 10;
    for (int i = 0; i < 1e4; i++) 
    {
        cout << n / m;
        n = n % m;
        n *= 10;
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