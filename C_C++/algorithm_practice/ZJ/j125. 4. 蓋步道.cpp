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
typedef vector<bool> vb;
typedef vector<vb> v2b;

const vi move_x = {-1, 1, 0, 0};
const vi move_y = {0, 0, 1, -1};

int n;
v2i graph;

bool check(int difference) {
    list<pii> li;
    v2b visited(n, vb(n));
    li.push_back({0, 0});
    visited[0][0] = 1;
    while (li.size()) {
        pii front = li.front();
        li.pop_front();
        int x = front.first;
        int y = front.second;
        for (int i = 0; i < 4; i++) {
            int dx = x + move_x[i];
            int dy = y + move_y[i];
            if (dx < 0 || dy < 0 || dx >= n || dy >= n) {
                continue;
            }
            if (visited[dx][dy]) {
                continue;
            }
            if (abs(graph[x][y] - graph[dx][dy]) > difference) {
                continue;
            }
            li.push_back({dx, dy});
            visited[dx][dy] = 1;
        }
    }
    
    return visited[n-1][n-1];
}

int get_depth(int difference) {
    list<pii> li;
    v2i depth(n, vi(n));
    v2b visited(n, vb(n));
    li.push_back({0, 0});
    visited[0][0] = 1;
    while (li.size()) {
        pii front = li.front();
        li.pop_front();
        int x = front.first;
        int y = front.second;
        for (int i = 0; i < 4; i++) {
            int dx = x + move_x[i];
            int dy = y + move_y[i];
            if (dx < 0 || dy < 0 || dx >= n || dy >= n) {
                continue;
            }
            if (visited[dx][dy]) {
                continue;
            }
            if (abs(graph[x][y] - graph[dx][dy]) > difference) {
                continue;
            }
            li.push_back({dx, dy});
            visited[dx][dy] = 1;
            depth[dx][dy] = depth[x][y] + 1;
        }
    }
    return depth[n-1][n-1];
}

void solve() {
    cin >> n;

    graph.resize(n, vi(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    int l = 1, r = 1e18;
    int depth;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << '\n' << get_depth(l) << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
