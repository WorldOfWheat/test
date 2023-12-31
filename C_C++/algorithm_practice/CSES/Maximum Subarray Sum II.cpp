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

int n;
int o, p;
vi arr;
vl prefix;
multiset<ll> ms;

void solve() 
{
    cin >> n >> o >> p;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    prefix.resize(n + 1);
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + arr[i-1];
    
    ll ans = -1e18;
    for (int i = o; i <= n; i++)
    {   
        if (i > p) ms.erase(ms.find(prefix[i - p - 1]));
        ms.insert(prefix[i - o]);
        ans = max(ans, prefix[i] - *(ms.begin()));        
    }
    
    cout << ans << '\n';
}

int main()
{
    fastio;

    solve();

    return 0;
}
