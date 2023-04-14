#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<int> arr;
vector<int> psum;
map<int, int> ma;

void solve() {
    cin >> n;
    arr.resize(n);
    for (auto &i : arr) {
        cin >> i;
    }

    psum.resize(n + 1);
    partial_sum(arr.begin(), arr.end(), psum.begin() + 1);
    
    for (auto i : psum) {
        ma[(i % n + n) % n]++;
    }

    int ans = 0;
    for (auto i : ma) {
        int temp = i.second;
        ans += (temp) * (temp - 1) / 2;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}