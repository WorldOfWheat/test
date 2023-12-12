#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int n, m;
vector<int> arr;
map<int, int> ma;

void solve()
{
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int current_sum = 0;
    int ans = 0;
    ma[0] = 1;
    for (int i = 0; i < n; i++) 
    {
        current_sum += arr[i];
        ans += ma[current_sum - m];
        ma[current_sum]++;
    }
    
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}