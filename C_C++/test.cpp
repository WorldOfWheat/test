#include <bits/stdc++.h>
#include <ranges> 

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    ranges::copy(views::iota(1, 500), ostream_iterator<int>(cout, " "));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}