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
    while (cin >> n) {
        vp arr(n);
        map<pii, int> record;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            arr[i].first = a;
            arr[i].second = b;
            record[{a, b}]++;
        }
        
        auto check = [] (map<pii, int> record, pii data) {
            return record[{data.first, data.second}] > 0 && record[{data.second, data.first}] > 0;
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (check(record, arr[i])) {
                ans++;
                record[{arr[i].first, arr[i].second}]--;
                record[{arr[i].second, arr[i].first}]--;
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
