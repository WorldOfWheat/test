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

int f(int num, int depth) {
    if (num == 9) {
        return depth;
    }
    int sum = 0;
    int temp_num = num;
    while (temp_num > 0) {
        sum += temp_num % 10;
        temp_num /= 10;
    }
    return f(sum, depth + 1);
}

void solve() {
    string s;
    while (cin >> s) {
        if (s == "0") {
            break;
        }
        
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] - '0';
        }
        if (sum % 9 != 0) {
            cout << s << " is not a multiple of 9.\n";
            continue;
        }
        
        int ans = f(sum, 0);
        cout << s << " is a multiple of 9 and has 9-degree " << ans + 1 << ".\n";
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
