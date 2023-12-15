#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int n, m;
vector<pii> arr;

void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++) 
        {
            int l = j + 1, r = n - 1;
            int sum = arr[i].first + arr[j].first + arr[l].first + arr[r].first;
            while (l < r)
            {
                if (sum > m) r--;
                if (sum < m) l++;
                if (sum == m) 
                {
                    cout << arr[i].second << ' ' << arr[j].second << ' ' << arr[l].second << ' ' << arr[r].second << '\n';
                    return;
                }
                sum = arr[i].first + arr[j].first + arr[l].first + arr[r].first;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}