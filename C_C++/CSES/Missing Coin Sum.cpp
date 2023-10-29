#include <bits/stdc++.h>
#include <ranges> 

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> arr;

void solve()
{
    cin >> n;

    arr.resize(n);

    for (auto &i : arr)
        cin >> i;
    
    sort(arr.begin(), arr.end());

    ll ans = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > ans)  {
            cout << (ans) << '\n';
            return;
        }

        ans += arr[i];
    }

    cout << ans << '\n';;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}