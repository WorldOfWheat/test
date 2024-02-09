#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;

void solve() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        vi arr(n);
        int minimum_index = 0, minimum = 1e18;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] /= m;
            if (arr[i] < minimum) {
                minimum = arr[i];
                minimum_index = i;
            }
        }
        
        k /= m;

        int ans = 0;
        for (int i = minimum_index + 1; i < n; i++) {
            if (arr[i] - arr[i-1] > k) {
                int take = arr[i] - (arr[i-1] + k);
                ans += take;
                arr[i] -= take;
            }
            else if (arr[i-1] - arr[i] > k) {
                int take = arr[i-1] - (arr[i] + k);
                ans += take;
                arr[i-1] -= take;
                i -= 2;
            }
        }
        for (int i = minimum_index - 1; i >= 0; i--) {
            if (arr[i] - arr[i+1] > k) {
                int take = arr[i] - (arr[i+1] + k);
                ans += take;
                arr[i] -= take;
            }
            else if (arr[i + 1] - arr[i] > k) {
                int take = arr[i+1] - (arr[i] + k);
                ans += take;
                arr[i+1] -= take;
                i += 2;
            }
        }
        
        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
