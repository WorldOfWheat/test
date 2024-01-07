#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n;
vi arr;
vi record;

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    record.resize(100 + 1);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j]) 
            {
                ans++;
                record[i+1] = 1;
                break;
            }
        }
    }

    cout << ans << '\n';
    int count = 0;
    for (int i = 1; i <= 100; i++) 
    {
        if (record[i] == 1) 
        {
            cout << i;
            count++;
            if (count != ans) cout << ' ';
            else return;
        }
    }
}

int main()
{
    fastio;
    solve();
    return 0;
}
