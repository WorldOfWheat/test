#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;

void solve()
{
    cin >> n;

    arr.resize(n + 1);

    arr[0] = 1e9;
    for (int i = 0; i < n; i++) 
    {
        int a;
        cin >> a;
        arr[a] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] < arr[i - 1]) ans++;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}