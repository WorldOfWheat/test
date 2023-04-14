#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

void solve() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    stringstream ss;
    do {
        for (auto i : arr) {
            ss << i << ' ';
        }
        ss << '\n';
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ss.str() << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}