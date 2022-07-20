#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define db(x) cout << x << endl
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[10+1] = {0};
    for (int i = 1; i <= 10; i++) {
        cin >> arr[i];
    }
    int n;
    cin >> n;
    int arr2[n+1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> arr2[i];
    }
    int mini = 1e18;
    int maxi = -1e18;
    for (int i = 1; i <= n; i++) {
        int mini2 = 1e18;
        int maxi2 = -1e18;
        for (int j = 1; j <= 10; j++) {
            if (arr2[i] - arr[j] < 0) {
                continue;
            }
            mini2 = min(mini2, arr2[i] - arr[j]);
            maxi2 = max(maxi2, arr2[i] - arr[j]);
        }
        mini = min(mini2, mini);
        maxi = max(maxi, maxi2);
    }
    cout << (mini) << endl;

    return 0;
}
