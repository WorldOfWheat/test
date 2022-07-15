#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int dir_ud[4] = {1, -1, 0, 0};
    const int dir_lr[4] = {0, 0, -1, 1};

    int t;
    int times = 1;
    while (cin >> t) {
        cout << "Case " << times << ":\n";
        times++;
        int n, m;
        cin >> n >> m;
        int arr[n+1][m+1];
        memset(&arr, 0, sizeof(arr));
        int start = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int a;
                cin >> a;
                if (i == 1 && a == 1) {
                    start = j;
                }
                arr[i][j] = a;
            }
        }
        queue<tp> q;
        q.push({1, start, 2});
        arr[1][start] = -1;
        while (!q.empty()) {
            tp f = q.front();
            int a = get<0>(f);
            int b = get<1>(f);
            int c = get<2>(f);
            for (int i = 0; i < 4; i++) {
                int &d = arr[a][b + dir_lr[i] ];
                int &e = arr[a + dir_ud[i]][b];

                if (d == 1 && dir_lr[i] != 0) {
                    d = c;
                    q.push( {a, b + dir_lr[i], c+1} );
                }
                if (e == 1 && dir_ud[i] != 0 ) {
                    if ( !(t==2 && i != 0) ) {
                        e = c;
                        q.push( {a + dir_ud[i], b, c+1} );
                    } else {
                        e = 0;
                        q.push( {a + dir_ud[i], b, 0} );
                    }
                }
            }
            q.pop();
        }
        arr[1][start] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
