#include <bits/stdc++.h>

using namespace std;


void solve() {
    string str = "taest";
    int length = str.length();
    for (int i = 0; i < length / 2; i++) {
        cout << str[i] << ' ' << str[length - 1 - i];
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}