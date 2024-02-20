#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;

void solve() {
    int n;
    while (cin >> n) {
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vi record1;
        vi record2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    record1.push_back(arr[i] * arr[j] + arr[k]);
                    if (arr[k] != 0) {
                        record2.push_back((arr[i] + arr[j]) * arr[k]);
                    }
                }
            }
        }
        
        sort(record2.begin(), record2.end());
        
        int ans = 0;
        for (int i = 0; i < record1.size(); i++) {
            auto lower = lower_bound(record2.begin(), record2.end(), record1[i]);
            auto upper = upper_bound(record2.begin(), record2.end(), record1[i]);            
            if (lower == record2.end()) {
                continue;
            }
            ans += upper - lower;
        }
        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
