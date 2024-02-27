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

int n, m;
vi arr;
vi arr2;

void solve() {
    cin >> n >> m;
    
    arr.resize(n);
    for (int& i : arr) {
        cin >> i;
    }

    arr2.resize(m);
    for (int& i : arr2) {
        cin >> i;
    }
    
    vi prefix_sum(2 * n + 2);
    for (int i = 1; i <= 2 * n + 1; i++) {
        prefix_sum[i] =  prefix_sum[i-1] + arr[(i-1) % n];
    }
    prefix_sum.insert(prefix_sum.begin() + n, prefix_sum[n]);
    
    int last = 0;
    for (int i = 0; i < m; i++) {
        auto lower = lower_bound(prefix_sum.begin(), prefix_sum.end(), arr2[i] + prefix_sum[last]);
        int index = lower - prefix_sum.begin();
        index %= n + 1;
        last = index;
    }
    
    cout << last % n << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
