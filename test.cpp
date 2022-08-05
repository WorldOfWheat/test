#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n;
vector<int> ve_table((int) 3e4 + 1);

int dfs() {
    if (x < 0) {
        return 0;
    }
    if (x == 0) {
        return 1;
    }
    if (ve_table[x] != 0) {
        return ve_table[x] / 2;
    }
    
    int a = dfs(x - 1);
    int b = dfs(x - 5); 
    int c = dfs(x - 10);
    int d = dfs(x - 25); 
    int e = dfs(x - 50);
    int f = a + b + c + d + e;
    ve_table[x] = f;
    return f;
}

void solve() {

    ve_table[1] = 1;
    cout << (dfs(n)) << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
