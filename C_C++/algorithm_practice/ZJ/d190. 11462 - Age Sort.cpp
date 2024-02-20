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

void counting_sort(vi& arr) {
    vi counter(100 + 1);
    for (int i = 0; i < arr.size(); i++) {
        counter[arr[i]]++;
    }

    int j = 0;
    for (int i = 0; i < counter.size(); i++) {
        while (counter[i] != 0) {
            arr[j] = i;
            j++;
            counter[i]--;
        }
    }
}

void solve() {
    while (true) {
        int n;
        cin >> n;
        
        if (n == 0) {
            break;
        }

        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        counting_sort(arr);
        
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
