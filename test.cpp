#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x > z; x--)
#define ln "\n"
#define sp " "
#define maxn (int) 1e6 + 1

using namespace std;

vector<int> graph[maxn];
vector<int> color(maxn);
bitset<maxn> vis;

class DSU {

    public:

        DSU(int x) {
            _size = x + 1;
            data.resize(_size);
            rep (i, 0, _size) {
                data[i] = i;
            }
        }

        int query(int x) {
            if (data[x] == x) {
                return x;
            }
            return data[x] = query(data[x]);
        }

        void update(int x, int y) {
            int a = query(x);
            int b = query(y);
            data[a] = b;
        }

    private:

        int _size;
        vector<int> data;


};

void dfs(int x, int y) {

    if (vis[x]) {
        return;
    }
    vis[x] = 1;
    color[x] = y ^ 3;

    for (auto i : graph[x]) {
        dfs(i, y ^ 3);
    }

}

void solve() {

    int n, m;
    cin >> n >> m;

    rep (i, 0 , m) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int k = 4;
    rep (i, 0, n) {
        if (vis[i]) {
            continue;
        }
        dfs(i, k);
        k = max(k, k ^ 3) + 1;
    }

    int o, p;
    cin >> o >> p;
    rep (i, 0, o) {
        rep (j, 0, p) {
            int a, b;
            cin >> a >> b;
            
        }
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
