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

bool check(vi& arr, int amount, int diameter) {
    int current_index = 1;
    int counter = 1;
    int current_accumulation = 0;
    while (current_index < arr.size()) {
        if (current_accumulation > diameter) {
            counter++;
            current_accumulation = 0;
        }
        current_accumulation += arr[current_index] - arr[current_index - 1];
        current_index++;
    }
    if (current_accumulation > diameter) {
        counter++;
        current_accumulation = 0;
    }
    return counter <= amount;
}

void solve() {
    int n, m;
    while (cin >> n >> m) {
        vi arr(n);
        for (int& i : arr) {
            cin >> i;
        }
        
        sort(arr.begin(), arr.end());
        
        int l = 0, r = 1e18;
        while (l < r) {
            int mid = (l + r) >> 1ll;
            if (check(arr, m, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        cout << l << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
