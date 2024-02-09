#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<v2p> v3p;
typedef vector<string> vs;

int n, m;
int* arr;

void solve() {
    cin >> n >> m;
    
    arr = new int[n]();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_map<int, int> record;
    int l = 0, r = 0;
    int ans = 0;
    int count = 1;
    record[arr[r]]++;
    while (l < n) {
        while (count <= m && r < n) {
            r++;
            if (record[arr[r]] == 0) count++;
            record[arr[r]]++;
        }
        ans += r - l;

        record[arr[l]]--;
        if (record[arr[l]] == 0) count--;
        l++;
    }
    
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
