#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

string str;
int n;

void solve()
{
    cin >> str >> n;
    for (int i = 0; i < str.length(); i++) 
    {
        switch (n)
        {
            case 1:
                if (islower(str[i])) cout << str[i];
                break;
            case 2:
                if (!islower(str[i]) && isalpha(str[i])) cout << str[i];
                break;
            case 3:
                if (isdigit(str[i])) cout << str[i];
                break;
        }
    }
}

signed main()
{
    fastio;
    solve();
    return 0;
}
