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

void solve() {
    int n, m;
    cin >> n >> m;
    
    v2i graph(n + 2, vi(m + 2, -1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
        }
    }
    
    const vi move_x = {1, -1, 0, 0};
    const vi move_y = {0, 0, 1, -1};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (graph[i][j] == -1) {
                continue;
            }
            for (int l = 0; l < 4; l++) {
                int dx = move_x[l] + i;                    
                int dy = move_y[l] + j;                    
                while (dx != 0 && dx != n + 1 && dy != 0 && dy != m + 1 && graph[dx][dy] == -1) {
                    dx += move_x[l];
                    dy += move_y[l];
                }
                if (dx == 0 || dx == n + 1 || dy == 0 || dy == m + 1) {
                    continue;
                }
                if (graph[i][j] == graph[dx][dy]) {
                    ans += graph[i][j];
                    graph[i][j] = -1;
                    graph[dx][dy] = -1;
                    break;
                }
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
