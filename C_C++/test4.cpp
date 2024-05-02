
#include <bits/stdc++.h>      
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);      
#define int long long      
      
using namespace std;      
      
typedef pair<int, int> pii;      
typedef vector<int> vi;      
typedef vector<vi> v2i;      
typedef vector<v2i> v3i;      
typedef vector<string> vs;      
typedef vector<vs> v2s;      
typedef vector<pii> vp;      
typedef vector<vp> v2p;      
typedef vector<bool> vb;      
typedef vector<vb> v2b;      

int f(int start, int last, int d) {
    if (start == last) {
        return last;
    }
    return start + f(start + d, last, d);
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << f((a % c == 0 ? a : a - (a % c) + c), b - (b % c), c) << '\n';
}    
      
signed main() {      
    fastio;      
    solve();      
    return 0;      
}  