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

void record_number(int& record, int num1, int num2) {
    if (num1 < 10000) record |= 1;
    while (num1 > 0) {
        record |= 1 << (num1 % 10);
        num1 /= 10;
    }

    if (num2 < 10000) record |= 1;
    while (num2 > 0) {
        record |= 1 << (num2 % 10);
        num2 /= 10;        
    }
}

void solve() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        bool flag = false;
        for (int i = 1234; i <= 98765 / n; i++) {
            int j = n * i;            
            int record = 0;
            record_number(record, i, j);
            if ((record ^ ((1 << 10) - 1)) == 0) {
                if (j < 10000) {
                    cout << "0";
                }
                cout << j;
                cout << " / ";
                if (i < 10000) {
                    cout << "0";
                }
                cout << i;
                cout << " = " << n << '\n';
                flag = true;
            }
        }
        if (!flag) {
            cout << "There are no solutions for " << n << ".\n";
        }
        cout << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
