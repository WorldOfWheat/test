#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define ll long long;
#define pii pair<int, int>;

using namespace std;

<<<<<<< HEAD
typedef long long ll;

int n, m;

=======
>>>>>>> f10d61b (Update .gitignore)
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