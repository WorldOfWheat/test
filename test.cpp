#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> ve;
vector<int> ve2;

class bigIntegerCal {
    public:
        vector<int> mul(vector<int> x, vector<int> y) {
            int _size = 1;
            int a = x.size();
            int b = y.size();
            while (_size < (a + b - 1)) {
                _size <<= 1;
            }

            x.resize(_size);
            y.resize(_size);

            ntt(x, _size, false);
            ntt(y, _size, false);

            for (int i = 0; i < _size; i++) {
                x[i] = 1ll * x[i] * y[i] % P;
            }

            ntt(x, _size, true);

            int remain = (_size - (a + b)) + 1;
            vector<int> res;
            int carry = 0;
            for (int i = _size - remain - 1; i >= 0; i--) {
                int a = carry + x[i];
                res.push_back(a % 10);
                carry = a / 10;
            }
            if (carry != 0) {
                res.push_back(carry);
            }
            return res;
        }

        void ntt(vector<int> &x, int _size, bool oper) {
            for (int i = 1, o = 0; i < _size; i++) {
                int p = _size >> 1;
                o ^= p;
                while (!(o & p)) {
                    p >>= 1;
                    o ^= p;
                }
                if (i < o) {
                    swap(x[i], x[o]);
                }
            }
            for (int i = 2; i <= _size; i <<= 1) {
                int p = i >> 1;
                int gn = fastpow(G, (P - 1) / i);
                for (int j = 0; j < _size; j+=i) {
                    int g = 1;
                    for (int k = 0; k < p; k++) {
                        int temp = 1ll * x[j+k+p] * g % P;
                        x[j+k+p] = (x[j+k] - temp + P) % P;
                        x[j+k] = (x[j+k] + temp) % P;
                        g = 1ll * g * gn % P;
                    }
                }
            }
            if (oper) {
                reverse(x.begin()+1, x.begin() + _size);
                int inv = fastpow(_size, P-2);
                for (int i = 0; i < _size; i++) {
                    x[i] = 1ll * x[i] * inv % P;
                }
            }
        }

    private:
        const int G = 3, P = 998244353;

        int fastpow(int x, int y) {
            int sum = 1;
            while (y > 0) {
                if (y & 1) {
                    sum = 1ll * sum * x % P;
                }
                y >>= 1;
                x = 1ll * x * x % P;
            }
            return sum;
        }

};

void solve() {

    char in;
    bool flag = false;
    while (in = getchar()) {
        if (in == '\n') {
            if (flag) {
                break;
            }
            flag = true;
            continue;
        }
        if (isdigit(in)) {
            if (!flag) {
                ve.push_back(in - '0');
            }
            else {
                ve2.push_back(in - '0');
            }
        }
    }
    bigIntegerCal bic;

    vector<int> ans = bic.mul(ve, ve2);
    stringstream ss;
    bool flag2 = false;

    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        ss << (*it);
        if (*it != 0) {
            flag2 = true;
        }
    }
    if (flag2) {
        cout << ss.str();
    }
    else {
        cout << 0;
    }

    cout << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
