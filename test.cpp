#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define sp " "
#define ln "\n"

using namespace std;

const V dx = {1, -1, 0, 0};
const V dy = {0, 0, 1, -1};
int n, m;
V ve;
VV graph;

void solve() {

    cin >> n >> m;

    ve.resize(m);
    graph.resize(n + 1, V(n + 1));

    rep (i, 0, m) {
        cin >> ve[i];
    }

    int end = n / 2 + 1;
    int dir = 0;
    int nowX = 1, nowY = n;
    int cnt = n - 1;
    int now = 1;

    while (nowX != end && nowY != end) {
        rep2 (i, 0, cnt - 1) {
            graph[nowX][nowY] = now++;
            if (dir == 0) {
                nowX++;
            }
            else if (dir == 1) {
                nowY--;
            }
            else if (dir == 2) {
                nowX--;
            }
            else {
                nowY++;
            }
        }
        dir++;
        if (dir == 4) {
            cnt-=2;
            nowX++;
            nowY--;
            dir = 0;
        }
    }
    graph[end][end] = n * n;

    /*rep2 (i, 1, n) {
        rep2 (j, 1, n) {
            cerr << graph[i][j] << sp;
        }
        cerr << ln;
    }*/

    dir = 0;
    nowX = 1, nowY = n;
    cnt = n - 1;
    int ans = 0;
    
    while (nowX != end && nowY != end) {
        rep2 (i, 0, cnt - 1) {
            ans++;
            rep (j, 0, m) {
                if (graph[nowX][nowY] == ve[j]) {
                    int maxi = 0;
                    rep (k, 0, 4) {
                        int moveX = nowX + dx[k];
                        int moveY = nowY + dy[k];

                    }
                    continue;
                }
            }
            if (dir == 0) {
                nowX++;
            }
            else if (dir == 1) {
                nowY--;
            }
            else if (dir == 2) {
                nowX--;
            }
            else {
                nowY++;
            }
        }
        dir++;
        if (dir == 4) {
            cnt-=2;
            nowX++;
            nowY--;
            dir = 0;
        }
    }

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
