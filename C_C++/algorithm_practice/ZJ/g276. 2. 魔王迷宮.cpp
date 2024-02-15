#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;
typedef vector<pii> v2p;

struct king
{
    int x, y;
    int dx, dy;
    bool dead = false;
};


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    v2i boom(n, vi(m));
    vector<king> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].dx >> arr[i].dy;
    }
    
    int count = 0;
    while (true) {
        bool flag = false;
        for (int i = 0; i < k; i++) {
            if (!arr[i].dead) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            break;
        }

        for (int i = 0; i < k; i++) {
            if (arr[i].dead) {
                continue;
            }

            boom[arr[i].x][arr[i].y]++;
            if (arr[i].x + arr[i].dx < 0 || arr[i].x + arr[i].dx >= n) {
                arr[i].dead = true;
                continue;
            }
            if (arr[i].y + arr[i].dy < 0 || arr[i].y + arr[i].dy >= m) {
                arr[i].dead = true;
                continue;
            }

            arr[i].x = arr[i].x + arr[i].dx;
            arr[i].y = arr[i].y + arr[i].dy;
        }

        vp explosion;
        for (int i = 0; i < k; i++) {
            if (!arr[i].dead && boom[arr[i].x][arr[i].y] >= 1) {
                arr[i].dead = true;
                explosion.push_back({arr[i].x, arr[i].y});
            }
        }
        for (auto i : explosion) {
            boom[i.first][i.second] = 0;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += boom[i][j] >= 1;            
        }
    }
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
