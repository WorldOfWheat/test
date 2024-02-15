#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

void solve() {
    double n, m, l, k;
    while (cin >> n >> m >> l >> k) {
        if (n == 0) {
            break;
        }
        int day = 1;        
        double current = 0;
        double increasement = m;
        double rate = increasement * (k / 100);
        bool flag = false;
        while (true) {
            current += increasement;            
            if (current > n) {
                flag = true;
                break;
            }
            current -= l;
            if (current < 0) {
                flag = false;
                break;
            }
            increasement = increasement - rate;
            increasement = max((double) 0, increasement);
            day++;
        }
        if (flag) {
            cout << "success on day " << day << '\n';
        }
        else {
            cout << "failure on day " << day << '\n';
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
