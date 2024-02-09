#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

void solve() {
    int n, m, l, q;
    while (cin >> n >> m >> l >> q) {
        v2i graph(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        
        auto bfs = [] (v2i* graph, vi* record, int root) {
            queue<int> qu;
            qu.push(root);
            while (qu.size()) {
                int front = qu.front();
                qu.pop();
                (*record)[front] = 1;
                for (auto i : (*graph)[front]) {
                    if ((*record)[i]) {
                        continue;
                    }
                    qu.push(i);
                }
            }
        };
        
        vi record(n + 1);
        for (int i = 0; i < l; i++) {
            int a;
            cin >> a;
            bfs(&graph, &record, a);
        }
        for (int i = 0; i < q; i++) {
            int a;
            cin >> a;
            if (record[a]) {
                cout << "TUIHUOOOOOO\n";
            } else {
                cout << "YA~~\n";
            }
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
