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

const int MOD = 1e9 + 7;
int n, m;
vi arr;
vi zero_indexes;

void solve() 
{
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        if (arr[i] == 0) zero_indexes.push_back(i);
    }
    
    
}

int main()
{
    fastio;

    solve();

    return 0;
}