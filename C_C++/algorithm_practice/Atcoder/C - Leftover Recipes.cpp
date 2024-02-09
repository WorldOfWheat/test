#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;

int n;
int* arr;
pii* arr2;

void solve() {
    cin >> n;
    
    arr = new int[n]();
    arr2 = new pii[n]();
    
    int maximum = -1e9;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        maximum = max(maximum, arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i].second;
    }
    
    int ans = -1e9;
    for (int i = 0; i <= maximum; ++i) {
        int minimum_y = 1e9;
        for (int j = 0; j < n; j++) {
            if (i * arr2[j].first > arr[j]) {
                minimum_y = -1e9;
                break;
            }
            else if (arr2[j].second != 0) {
                minimum_y = min(minimum_y, (arr[j] - arr2[j].first * i) / arr2[j].second);
            }
        }
        ans = max(ans, i + minimum_y);
    }
    
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
