#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;

int n, m;
vector<int> arr;

void solve()
{
    cin >> n >> m;
    
    int maximum_1 = -1e9;
    int maximum_2 = -1e9;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        maximum_1 = max(maximum_1, a);
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        maximum_2 = max(maximum_2, a);
    }
    
    if (maximum_1 == maximum_2) cout << "possible\n";
    else cout << "impossible\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}