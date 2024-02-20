#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;

void solve() {
    int n, m;
    cin >> n >> m;

    v2i graph(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    
    int ans = 0;
    const vi move_x = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    const vi move_y = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool flag = false;
            for (int k = 0; k < 9; k++) {
                int dx = move_x[k] + i;
                int dy = move_y[k] + j;
                if (dx < 0 || dy < 0 || dx >= n || dy >= m) {
                    continue;
                }
                if (dx == i && dy == j) {
                    continue;
                }
                if (graph[i][j] == graph[dx][dy]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans++;
            }
        }
    }
    
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
