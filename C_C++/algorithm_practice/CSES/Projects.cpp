#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;

struct project {
    int start, end;
    int reward;
};

int n;
vector<project> arr;

void solve() {
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].end >> arr[i].reward;
    }
    
    vi mapping;
    for (int i = 0; i < n; i++) {
        mapping.push_back(arr[i].start);
        mapping.push_back(arr[i].end);
    }
    
    auto compare = [] (project x, project y) {
        if (x.start > y.start) return false;
        if (x.start < y.start) return true;
        if (x.end > y.end) return false;
        if (x.end < y.end) return true;
        return true;
    };

    sort(mapping.begin(), mapping.end());
    mapping.erase(unique(mapping.begin(), mapping.end()), mapping.end());
    sort(arr.begin(), arr.end(), compare);
    
    vvp end_record(n * 2 + 1);
    for (int i = 0; i < n; i++) {
        arr[i].start = lower_bound(mapping.begin(), mapping.end(), arr[i].start) - mapping.begin() + 1;
        arr[i].end = lower_bound(mapping.begin(), mapping.end(), arr[i].end) - mapping.begin() + 1;
        end_record[arr[i].end].push_back({arr[i].reward, arr[i].start});
    }
    
    // for (int i = 0; i < n; i++) {
    //     cerr << arr[i].start << ' ' << arr[i].end << '\n';
    // }
    
    vi dp(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++) {
        dp[i] = dp[i-1];
        for (auto j : end_record[i]) {
            dp[i] = max(dp[i], dp[j.second - 1] + j.first);
        }
    }
    
    cout << dp[n * 2] << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
