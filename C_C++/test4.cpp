#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int q;
ll n;

void solve()
{
    cin >> q;
    while (q--)
    {
        cin >> n;    
        ll mid = sqrt(n);
        ll l = max(2ll, mid - (ll) 1e6);
        ll r = mid + (int) 1e6;
        for (ll i = l; i <= r; i++) 
        {
            if (n % i == 0) 
            {
                cout << i << ' ' << (n / i) << '\n';
                break;
            }
        }
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