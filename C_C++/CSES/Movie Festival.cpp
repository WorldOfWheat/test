#include <bits/stdc++.h>
#include <ranges> 

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;
vector<int> arr2;

void solve()
{
    cin >> n;

    arr.resize(n);
    arr2.resize(n);

    for (auto &i : arr) 
    {
        cin >> i.second >> i.first;
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int now = 0;
    for (int i = 0; i < arr.size(); i++) 
    {
        if (arr[i].second < now) continue;
        ans++;
        now = arr[i].first;
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