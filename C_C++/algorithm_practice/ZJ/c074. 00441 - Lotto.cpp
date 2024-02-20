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

void f(v2i& record, vi& temp, vi& arr, int index, int depth) {
    if (depth == 6) {
        record.push_back(temp);
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        temp.push_back(arr[i]);
        f(record, temp, arr, i + 1, depth + 1);
        temp.pop_back();
    }
}

void solve() {
    int n;
    bool first_time = false;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        if (first_time) {
            cout << '\n';
        }
        first_time = 1;
        
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        v2i record;
        vi temp;
        f(record, temp, arr, 0, 0);
        
        for (int i = 0; i < record.size(); i++) {
            for (int j = 0; j < record[i].size(); j++) {
                cout << record[i][j];
                if (j != record[i].size() - 1) cout << ' ';
            }
            cout << '\n';
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
