#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug_container(container) for (auto i : container) cerr << i << ' '; cerr << '\n';
#define debug(x) cerr << x << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

const int MOD = 1e9 + 7;
int t, n;
vector<vi> record(1e6 + 1, vi(8));

int f(int x, char lines) 
{
    if (x == 1)
    {
        if (lines == 0b000) return 1;
        if ((lines & 0b100) && (lines != 0b111)) return 1;
        return 2;
    }

    if (record[x][lines] != 0) return record[x][lines];

    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        if (((lines == 0b101) || (lines == 0b110) || (lines == 0b100)) && !(i & 0b100)) continue;
        if ((lines == 0b000 || lines == 0b010 || lines == 001) && (i & 0b100)) continue;
        if (i == 0b001 || i == 0b010) continue;
        ans += f(x-1, i);
        ans %= MOD;
    }
    return record[x][lines] = ans;
}

void solve() 
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << 2 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 0; i < 8; i++) 
        {
            if (i == 0b001 || i == 0b010) continue;
            ans += f(n-1, i);
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}

int main()
{
    fastio;

    solve();

    return 0;
}