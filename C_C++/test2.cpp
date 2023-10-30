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
    table.push_back(9);
    table2.push_back(1);
    table3.push_back(1);
    ll now = 90;
    for (int i = 2; i <= 17; i++) 
    {
        table.push_back(i * now);
        now *= 10;
        table2.push_back(table2.back() * 10);
        table3.push_back(i);
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
        int digit = n - (table[index - 1]);
        int th = (digit - 1) / (table3[index]);
        int num = table2[index] + th;
        char num_digit = to_string(num)[(digit - 1) % table3[index]];
        // cout << index << ' ' << digit << ' ' << th << ' ' << num << '\n';
        cout << num_digit << '\n';
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