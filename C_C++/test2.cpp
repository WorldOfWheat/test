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

char c;

void solve() {
    cin >> c;
    switch (c) {
        case 'A':
            cout << "你越派、我越愛\n";
            break;
        case 'B':
            cout << "happy\n";
            break;
        case 'C':
            cout << "幽浮也是福。\n";
            break;
        case 'D':
            cout << "菜就多練\n";
            break;
        case 'E':
            cout << "確實\n";
            break;
        case 'F':
            cout << "特別會吃飯捲\n";
            break;
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
