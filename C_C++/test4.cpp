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

const int MOD = 998244353;
int n, m;
vi arr;
v2i dp;

int f(int index, int goal) {
    if (dp[index][goal] != -1) {
        return dp[index][goal];
    }
    if (goal == 0) {
         return 1;
    }
    if (index == n) {
        return 0;
    }

    int result = 0;
    for (int i = 0; i <= arr[index]; i++) {
        if (goal - i < 0) {
            break;
        }
        result += f(index + 1, goal - i) % MOD;
        result %= MOD;
    }

    return dp[index][goal] = result;
}

void solve() {
    cin >> m >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= m; i++) {
        cout << f(0, i);
        if (i != m) {
            cout << ' ';
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
