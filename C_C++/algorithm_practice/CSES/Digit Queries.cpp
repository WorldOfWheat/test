#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll q;
ll n;
vector<pair<ll, ll>> table;
vector<ll> table_prefixSum;

ll binary_search_table(ll x)
{
    if (x <= table_prefixSum[1])
    {
        return 0;
    }

    ll result = 1;
    for (ll i = table.size() / 2; i > 0; i >>= 1) 
    {
        while (result + i < table_prefixSum.size() && (table_prefixSum[result + i] < x))
        {
            result += i;
        }
    }

    return result;
}

void solve() 
{
    ll lower = 1, upper = 9;
    for (ll i = 1; i <= 18; i++)
    {
        table.push_back({lower, upper});
        lower *= 10;
        upper = upper * 10 + 9;
    }

    table_prefixSum.push_back(0);
    for (ll i = 1; i <= 17; i++) {
        table_prefixSum.push_back(table_prefixSum.back() + (table[i-1].second - table[i-1].first + 1) * i);
    }

    // for (auto i : table)
    // {
    //     cout << i.first << ' ' << i.second << '\n';
    // }
    // for (auto i : table_prefixSum)
    // {
    //     cout << i << '\n';
    // }

    cin >> q;

    for (ll i = 0; i < q; i++)
    {
        cin >> n;
        if (n <= 9)
        {
            cout << n << '\n';
            continue;
        }
        ll length = binary_search_table(n) + 1;
        ll tmp = n - table_prefixSum[length - 1]; 
        ll number = table[length - 1].first + tmp / length;
        // cout << tmp << ' ' << length << '\n';
        if ((tmp % length) == 0)
        {
            number--;
            cout << (number % 10) << '\n';
            continue;
        }

        cout << to_string(number)[tmp % length - 1] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
