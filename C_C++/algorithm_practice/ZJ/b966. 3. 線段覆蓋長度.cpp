#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;

int n;
vp arr;

void solve() {
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr.begin(), arr.end());
    
    pii last = {0, 0};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].first >= last.second) {
            ans += arr[i].second - arr[i].first;
            last = arr[i];
            continue;
        }
        if (arr[i].first < last.second) {
            if (arr[i].second < last.second) {
                continue;
            }
            ans += arr[i].second - last.second;
            last = arr[i];
        }
    }

    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
