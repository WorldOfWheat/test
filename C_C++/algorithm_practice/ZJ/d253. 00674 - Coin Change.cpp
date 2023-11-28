#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const vector<int> coins = {1,5,10,25,50};
int n;
vector<int> table;

void pre()
{
    table.resize(7489 + 5, 0);
    table[0] = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 1; j <= 7489; j++)
        {
            if (j - coins[i] >= 0) table[j] = 
        }
    }
}

void solve()
{
    pre();

    while (cin >> n)
    {
        cout << table[n] << '\n';
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
