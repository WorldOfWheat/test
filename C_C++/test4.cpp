#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int exgcd(int a, int b, int x, int y)
{
    if (b == 0) return a;
    
    return gcd(b, a % b);
}

void solve()
{
    
}

int main()
{
    fastio;

    solve();

    return 0;
}