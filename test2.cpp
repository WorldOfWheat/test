#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "

using namespace std;

const int dir[4] = {1, -1, 0, 0};
const int dir2[4] = {0, 0, -1, 1};
int n, m;

void solve() {

    cin >> n >> m;
    int arr[n][m];
    int x = 0, y = 0;
    int mini = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] < mini) {
                mini = arr[i][j];
                x = i;
                y = j;
            }
        }
    }
    int ans = arr[x][y];
    bool visited[n][m];
    memset(&visited, 0, sizeof(visited));
    visited[x][y] = true;
    while (true) {
        //cerr << (arr[x][y]) << ln;
        int mini2 = 1e18;
        int x_b = x;
        int y_b = y;
        for (int i = 0; i < 4; i++) {
            int a = x + dir2[i];
            int b = y + dir[i];
            if (a < 0 || a >= n) {
                continue;
            }
            if (b < 0 || b >= m) {
                continue;
            }
            //cerr << a << sp << b << sp << (arr[a][b]) << ln;
            if (arr[a][b] < mini2 && visited[a][b] == false) {
                x_b = a;
                y_b = b;
                mini2 = arr[a][b];
            }
        }
        if (x == x_b && y == y_b) {
            break;
        }
        x = x_b;
        y = y_b;
        visited[x][y] = true;
        ans += arr[x][y];
        //cerr << (ans) << ln;
    }
    cout << ans << ln;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

