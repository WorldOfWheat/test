#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;

void solve() {
    int n;
    cin >> n;
    
    vp arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr.begin(), arr.end(), [] (pii x, pii y) {
        if (x.first < y.first) return true;
        if (x.first > y.first) return false;
        if (x.second > y.second) return true;
        if (x.second < y.second) return false;
        return true;
    });
    
    int ans = 0;
    int maximum_right = -1e18;
    for (int i = 0; i < n; i++) {
        if (arr[i].first < maximum_right && arr[i].second > maximum_right) {
            ans += arr[i].second - maximum_right;
            maximum_right = arr[i].second;
        }
        else if (arr[i].second <= maximum_right) {
            continue;
        }
        else {
            ans += arr[i].second - arr[i].first;
        }

        maximum_right = max(arr[i].second, maximum_right);
    }
    
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
