#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

class bigCal {
    public:
        string add(string x, string y) {
            stringstream ss;
            int carry = 0;
            for (int i = max(x.length(), y.length()) - 1; i >= 0; i--) {
                while (i >= x.length()) {
                    x = "0" + x;
                }
                while (i >= y.length()) {
                    y = "0" + y;
                }
                int a = x[i] - '0';
                int b = y[i] - '0';
                int c = a + b + carry;
                ss << (c % 10);
                carry = c / 10;
            }
            if (carry != 0) {
                ss << carry;
            }
            string a = ss.str();
            reverse(a.begin(), a.end());
            return a;
        }
        string sub(string x, string y) {
            stringstream ss;
            for (int i = max(x.length(), y.length()) - 1; i >= 0; i--) {
                while (i >= x.length()) {
                    x = "0" + x;
                }
                while (i >= y.length()) {
                    y = "0" + y;
                }
                int a = x[i] - '0';
                int b = y[i] - '0';
                if (a >= b) {
                    ss << (a - b);
                }
                else {
                    ss << (10 + a - b);
                    x[i-1]--;
                }
            }
            string a = ss.str();
            reverse(a.begin(), a.end());
            return a;
        }
        string multi(string x, string y) {
            int a = x.length();
            int b = y.length();
            int len = max(a, b);
            while (x.length() < len) {
                x = "0" + x;
            }
            while (y.length() < len) {
                y = "0" + y;
            }
            return multi_cal(x, y);
        }
        void format(string &x) {
            while (x.length() > 1 && x[0] == '0') {
                x = x.substr(1, x.length());
            }
        }
    private:
        string multi_cal(string x, string y) {
            int len = x.length();
            if (len == 0) {
                return 0;
            }
            if (len <= 2) {
                int a = atoi(x.c_str());
                int b = atoi(y.c_str());
                return to_string(a*b);
            }
            int mid_f = len / 2;
            int mid_r = len - mid_f;

            string a_l = x.substr(0, mid_f);
            string a_r = x.substr(mid_f, mid_r);

            string b_l = y.substr(0, mid_f);
            string b_r = y.substr(mid_f, mid_r);

            string c1 = multi(a_l, b_l);
            string c2 = multi(a_r, b_r);
            string c3 = multi( add(a_l, a_r), add(b_l, b_r) );

            string d1 = c1;
            for (int i = 1; i <= 2*mid_r; i++) {
                d1 += "0";
            }

            string d2 = sub(c3, add(c1, c2));
            for (int i = 1; i <= mid_r; i++) {
                d2 += "0";
            }

            string result = add(d1, add(d2, c2) );

            return (result);
        }
};

void solve() {

    bigCal bc;
    string a;
    string b;
    char symbol;
    cin >> a >> symbol >> b;
    switch(symbol) {
        case '+': {
            string c = bc.add(a, b);
            bc.format(c);
            cout << c << endl;
            break;
        }
        case '-': {
            string c = bc.sub(a, b);
            bc.format(c);
            cout << c << endl;
            break;
        }
        case '*': {
            string c = bc.multi(a, b);
            bc.format(c);
            cout << c << endl;
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
