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

void f(v2p& graph, int x, int y) {
    const vi move_x = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    const vi move_y = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int r = graph.size();
    int c = graph[0].size();

    for (int i = 0; i < 9; i++) {
        if (i == 4) {
            continue;
        }

        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if (dx < 0 || dx >= r || dy < 0 || dy >= c) {
            continue;            
        }
        
        if (graph[dx][dy].first == 5)
            return;
    }
    
    for (int i = 0; i < 9; i++) {
        if (i == 4) {
            continue;
        }

        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if (dx < 0 || dx >= r || dy < 0 || dy >= c) {
            continue;
        }
        
        if (graph[dx][dy].first == 1)
            graph[dx][dy].second = 1;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    v2p graph(n, vp(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j].first;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j].first == 5)
                f(graph, i, j);
        }
    }
    
    pii ans = {0, 0};    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j].first == 1) {
                if (graph[i][j].second) {
                    ans.first++;
                }
                else {
                    ans.second++;
                }
            }
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
