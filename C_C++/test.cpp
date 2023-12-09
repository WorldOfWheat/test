#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int t;

vector<bool> primes_record;
vector<int> primes_table;

void linar_sive_theory(int maximum = 1e8)
{
    primes_record.resize(maximum + 1, true);

    for (int i = 2; i <= maximum; i++) 
    {
        if (primes_record[i]) primes_table.push_back(i);        

        int len = primes_table.size();
        for (int j = 0; j < len; j++) 
        {
            ll multiply = (ll) i * (ll) primes_table[j];
            if (multiply > maximum) break;
            primes_record[multiply] = false;
            if (i % primes_table[j] == 0) break;
        }
    }
}

void solve()
{
    linar_sive_theory();

    cin >> t;
    while (t--) 
    {
        ll n;
        cin >> n;
        for (auto i : primes_table)
        {
            if (n % i == 0)
            {
                cout << i << ' ' << n / i << '\n';
                break;
            }
        }
    }
}


int main()
{
    fastio;
    solve();
    return 0;
}
