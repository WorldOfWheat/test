#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
using cd = complex<double>;
__attribute__((optimize("-O3")))

const double PI = acos(-1);

void fft(vector<cd> &x) {
    const int _size = x.size();
    if (_size == 1) {
        return;
    }
    int mid = _size >> 1;
    vector<cd> left(mid);
    vector<cd> right(mid);
    for (int i = 0; i < mid; i++) {
        left[i] = x[i << 1];
        right[i] = x[(i << 1) + 1];
    }
    fft(left);
    fft(right);
    const double angle = PI / _size * 2;
    cd w(1), wn(cos(angle), sin(angle));
    for (int i = 0; i < mid; i++) {
        x[i] = left[i] + w * right[i];
        x[i + mid] = left[i] - w * right[i];
        w *= wn;
    }
}

void reverse_fft(vector<cd> &x) {
    int _size = x.size();
    if (_size == 1) {
        return;
    }
    int mid = _size >> 1;
    vector<cd> left(mid);
    vector<cd> right(mid);
    for (int i = 0; i < mid; i++) {
        left[i] = x[i << 1];
        right[i] = x[(i << 1) + 1];
    }
    reverse_fft(left);
    reverse_fft(right);
    const double angle = PI / _size * -1 * 2;
    cd w(1), wn(cos(angle), sin(angle));
    for (int i = 0; i < mid; i++) {
        x[i] = left[i] + w * right[i];
        x[i + mid] = left[i] - w * right[i];
        x[i] /= 2;
        x[i + mid] /= 2;
        w *= wn;
    }
}

stack<int> add(vector<int> x, vector<int> y) {
    const int len_x = x.size();
    const int len_y = y.size();
    int ptr_x = len_x - 1;
    int ptr_y = len_y - 1;
    stack<int> st_result;
    int carry = 0;
    while (ptr_x >= 0 && ptr_y >= 0) {
        int a = x[ptr_x] + y[ptr_y] + carry;
        st_result.push(a % 10);
        carry = a / 10;
        ptr_x--;
        ptr_y--;
    }
    while (ptr_x >= 0) {
        int a = x[ptr_x] + carry;
        st_result.push(a % 10);
        carry = a / 10;
        ptr_x--;
    }
    while (ptr_y >= 0) {
        int a = y[ptr_y] + carry;
        st_result.push(a % 10);
        carry = a / 10;
        ptr_y--;
    }
    return st_result;
}
stack<int> sub(vector<int> x, vector<int> y) {
    const int len_x = x.size();
    const int len_y = y.size();
    int ptr_x = len_x - 1;
    int ptr_y = len_y - 1;
    stack<int> st_result;
    while (ptr_x >= 0 && ptr_y >= 0) {
        int a = x[ptr_x] - y[ptr_y];
        if (a >= 0) {
            st_result.push(a);
        }
        else {
            st_result.push(a + 10);
            x[ptr_x - 1]--;
        }
        ptr_x--;
        ptr_y--;
    }
    while (ptr_x >= 0) {
        if (x[ptr_x] < 0) {
            x[ptr_x-1]--;
            st_result.push(x[ptr_x] + 10);
        }
        else {
            if (ptr_x == 0 && x[ptr_x] == 0) {
                break;
            }
            st_result.push(x[ptr_x]);
        }
        ptr_x--;
    }
    return st_result;
}

stack<int> mul(vector<int> x, vector<int> y) {
    vector<cd> ve_cd(x.begin(), x.end());
    vector<cd> ve_cd2(y.begin(), y.end());

    int _size = 1;
    while (_size < x.size() + y.size()) {
        _size <<= 1;
    }

    ve_cd.resize(_size);
    ve_cd2.resize(_size);

    fft(ve_cd);
    fft(ve_cd2);

    for (int i = 0; i < ve_cd.size(); i++) {
        ve_cd[i] *= ve_cd2[i];
    }

    reverse_fft(ve_cd);

    int remain = ( _size - (x.size() + y.size()) ) + 1;
    stack<int> st_result;
    int carry = 0;
    for (int i = _size - remain - 1; i >= 0 ; i--) {
        int a = round(ve_cd[i].real());
        int b = carry + a;
        //cout << a << " " << b << endl;
        st_result.push(b % 10);
        carry = b / 10;
        //ve_result[i] = round(ve_cd[i].real());
    }
    if (carry != 0) {
        st_result.push(carry);
    }
    return st_result;
}

char input;
vector<int> ve;
vector<int> ve2;
char symbol;

void solve() {

    bool flag = false;
    while (input != EOF) {
        input = getchar();
        if (input != ' ') {
            if ( isdigit(input) ) {
                if (!flag) {
                    ve.push_back(input - 48);
                }
                else {
                    ve2.push_back(input - 48);
                }
            }
            if ( ispunct(input) ) {
                symbol = input;
                flag = true;
            }
        }
    }
    switch (symbol) {
        case '+': {
            stack<int> st = add(ve, ve2);
            while (!st.empty()) {
                putchar(st.top() + 48);
                //cout << (st.top());
                st.pop();
            }
            break;
        }
        case '-': {
            stack<int> st = sub(ve, ve2);
            bool flag = true;
            while (!st.empty()) {
                if (st.top() != 0 || st.size() == 1) {
                    flag = false;
                }
                if (st.top() == 0 && flag) {
                    st.pop();
                    continue;
                }
                putchar(st.top() + 48);
                //cout << (st.top());
                st.pop();
            }
            break;
        }
        case '*': {
            stack<int> st = mul(ve, ve2);
            while (!st.empty()) {
                putchar(st.top() + 48);
                //cout << (st.top());
                st.pop();
            }
            break;
        }
    }
    cout << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
