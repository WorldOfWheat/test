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
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        int maximum = arr.back();
        int minimum = arr.front();
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i-1] > 1) {
                flag = false;
                break;
            }
        }
        
        cout << minimum << ' ' << maximum << ' ';
        if (!flag) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
