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

int dfs(v2i& graph, int root, vi& depth) {
    if (depth[root] != -1) {
        return depth[root];
    }

    int node_depth = 0;
    for (auto i : graph[root]) {
        node_depth = max(node_depth, dfs(graph, i, depth) + 1);
    }
    
    return depth[root] = node_depth;
}

void solve() {
    int n;
    cin >> n;
    
    v2i graph(n);
    vi indegree(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (a--) {
            int b;
            cin >> b;
            b--;
            indegree[b]++;
            graph[i].push_back(b);
        }
    }
    
    int root;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            root = i;
            break;
        }
    }
    
    cout << root + 1 << '\n';
    
    vi depth(n, -1);
    dfs(graph, root, depth);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += depth[i];
    }
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
