#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<v2p> v3p;
typedef vector<string> vs;

int n;
vi arr;

int f(int left, int right, vi* prefix_xor)
{
    if (left == right) return arr[left];
    
    int result = min(f(left, right - 1, prefix_xor) + arr[right], arr[left] + f(left + 1, right, prefix_xor));
    if (arr[left] == arr[right]) 
    {
        result = min(result, ((*prefix_xor)[right] ^ (*prefix_xor)[left+1]) % arr[left]);
    }

    return result;
}

void solve()
{
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vi prefix_xor(n + 1);
    for (int i = 1; i <= n; i++) prefix_xor[i] = arr[i-1] ^ prefix_xor[i-1];
    for (int i = 1; i <= n; i++) cerr << prefix_xor[i] << ' ';
    cerr << '\n';
    
    cout << f(0, n - 1, &prefix_xor) << '\n';
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
