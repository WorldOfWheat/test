#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int t;
ll n;
vector<ll> table;
vector<ll> table2;
vector<ll> table3;

void pre() 
{   
    ll now = 9;
    ll sum = 0;
    ll start = 1;
    for (int i = 1; i <= 17; i++) 
    {
        table.push_back(i * now + sum);
        sum += i * now;
        now *= 10;
        table2.push_back(start);
        start *= 10;
    }
    // for (int i = 0; i < table.size(); i++) cout << table[i] << '\n';
    // for (int i = 0; i < table2.size(); i++) cout << table2[i] << '\n';
}

void solve()
{
    pre();

    cin >> t;
    while (t--) 
    {
        cin >> n;
        if (n <= 9) 
        {
            cout << n << '\n';
            continue;
        }
        auto it = lower_bound(table.begin(), table.end(), n);
        int index = it - table.begin();
        ll backward = n - table[index - 1];
        ll digit = backward / (index + 1);
        if (backward % (index + 1) == 0) digit--;
        ll num = table2[index] + digit;
        int pos = backward % (index + 1);
        if (pos == 0) pos = index + 1;
        pos--;
        // cout << index << ' ' << backward << ' ' << digit << ' ' << num << ' ' << pos << "\n";
        cout << (to_string(num)[pos]) << '\n';
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