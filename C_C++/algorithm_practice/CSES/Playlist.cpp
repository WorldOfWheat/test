#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;
map<int, int> visited;

void solve()
{
    cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 1;
    int j = 0;
    visited[arr[j]]++;
    for (int i = 1; i < n; i++)
    {
        while (visited[arr[i]] > 0)
        {
            visited[arr[j]]--;
            j++;
        }
        visited[arr[i]]++;
        ans = max(ans, i - j + 1);
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