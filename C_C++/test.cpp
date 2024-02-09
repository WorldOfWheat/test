#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;

int n, m;
vi arr;
vp dp((1 << 20) + 1, {-1, -1});

pii get_grather(pii x, pii y) {
    if (x.first < y.first) return x;
    if (x.first > y.first) return y;
    if (x.second > y.second) return x;
    if (x.second < y.second) return y;
    return x;
}

pii f(int mask, int count, int remainder) {
    if (mask == 0) {
        return {count, remainder};
    }
    
    if (dp[mask].first != -1) {
        return dp[mask];
    }

    pii res = {1e18, -1e18};
    for (int i = 0; i < n; i++) {
        if ((mask & (1ll << i)) != 0) {
            mask ^= (1ll << i);
            if (remainder - arr[i] < 0) {
                res = get_grather(f(mask, count + 1, m - arr[i]), res);
            }
            else {
                res = get_grather(f(mask, count, remainder - arr[i]), res);
            }
            mask ^= (1ll << i);
        }
    }
    
    return dp[mask] = res;
}

void solve() {
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << f((1ll << n) - 1, 0, m).first + 1 << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
