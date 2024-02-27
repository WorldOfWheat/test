#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;

void solve() {
    int n, m;
    cin >> n >> m;
    
    v2i arr(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    v3i dp(3, v2i(n + 2, vi(m + 2, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == 1) {
                dp[0][i][j] = dp[1][i-1][j] + arr[i-1][j-1];
                continue;
            }
            dp[0][i][j] = max({dp[0][i][j-1], dp[0][i-1][j], dp[1][i-1][j]}) + arr[i-1][j-1];
        }
        for (int j = m; j >= 1; j--) {
            if (j == m) {
                dp[1][i][j] = dp[0][i-1][j] + arr[i-1][j-1];
                continue;
            }
            dp[1][i][j] = max({dp[1][i][j+1], dp[0][i-1][j], dp[1][i-1][j]}) + arr[i-1][j-1];
        }
    }

    int ans = -1e18;
    for (int i = 1; i <= m; i++) {
        ans = max({ans, dp[0][n][i], dp[1][n][i]});        
    }
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}

// ###################################################################################################

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<bool> vb;

const vi move_x = {0, -1, 0};
const vi move_y = {-1, 0, 1};

int n, m;
v2i graph;
v3i record;

int f(int x, int y, int direction) {
    if (record[direction][x][y] != -1e18) {
        return record[direction][x][y];
    }

    int maximum = -1e18;
    if (x == 0) {
        maximum = 0;
    }

    bool flag = false;
    for (int i = 0; i < 3; i++) {
        int dx, dy;
        dx = x + move_x[i];
        dy = y + move_y[i];
        if (dx < 0 || dy < 0 || dy >= m) {
            continue;
        }
        if (direction == 2 && i == 0) {
            continue;
        }
        if (direction == 0 && i == 2) {
            continue;
        }
        flag = 1;
        maximum = max(maximum, f(dx, dy, i));
    }    
    if (!flag) {
        return graph[x][y];
    }

    maximum += graph[x][y];
    
    return record[direction][x][y] = maximum;
}

void solve() {
    cin >> n >> m;
    
    graph.resize(n, vi(m));
    record.resize(3, v2i(n, vi(m, -1e18)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    
    int ans = -1e18;
    for (int i = 0; i < m; i++) {
        ans = max(ans, f(n - 1, i, 1));
    }
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
