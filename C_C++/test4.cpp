#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    ll n = 100000;
    for (int i = 0; i < 10; i++) n += (double) n * 0.08;
    cout << n << '\n';
}

int main()
{
    fastio;

    solve();

    return 0;
}