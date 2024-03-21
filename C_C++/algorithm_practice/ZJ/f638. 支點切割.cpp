#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<bool> vb;
typedef vector<vb> v2b;

int n, m;
vi arr;

int f(int l, int r, int depth) {
    if (depth == m) {
        return 0;
    }
    if (r - l < 3) {
        return 0;
    }

    vi prefix(r - l + 5, 0);
    vi suffix(r - l + 5, 0);
    for (int i = 1; i <= r - l; i++) {
        prefix[i] = prefix[i - 1] + arr[i + l - 1];        
    }
    for (int i = r - l - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + arr[i + l];        
    }

    vi prefix2(r - l + 1, 0);
    vi suffix2(r - l + 1, 0);
    for (int i = 1; i <= r - l; i++) {
        prefix2[i] = prefix2[i - 1] + prefix[i];        
    }
    for (int i = r - l - 1; i >= 0; i--) {
        suffix2[i] = suffix2[i + 1] + suffix[i + 1];        
    }
    
    int index = 0;
    int minimum = 1e18;
    for (int i = l + 1; i < r - 1; i++) {
        int diff = abs(prefix2[i - l] - suffix2[i - l]);
        if (minimum > diff) {
            minimum = diff;
            index = i;
        }
    }
    
    return arr[index] + f(l, index, depth + 1) + f(index + 1, r, depth + 1);
}

void solve() {
    while (cin >> n >> m) {
        
        arr.resize(n + 5);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << f(0, n, 0) << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
