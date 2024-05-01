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

mt19937 rng;

int randint(int min, int max) {
    return uniform_int_distribution<int>(min, max)(rng);
}

void shuffle(vi &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        swap(a[i], a[randint(i, n - 1)]);
    }
}

void solve() {
    for (int i = 0; i <= 3; i++) {
        vi arr;
        for (int j = 1; j <= 12; j++) {
            if (j & (1 << i)) {
                arr.push_back(j);
            }
        }
        shuffle(arr);
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
