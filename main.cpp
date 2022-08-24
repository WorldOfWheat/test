#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

void solve() {

    string str = "abc123def";
    regex reg("[0-9]+");
    smatch sm;
    cout << (regex_search(str, sm, reg)) << ln;

}

void fileStream() {
    freopen("test_input.txt", "r", stdin);
    freopen("test_output.txt", "w", stdout);
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    //fileStream();
    solve();

    return 0;

}
