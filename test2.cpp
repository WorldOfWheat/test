#include <bits/stdc++.h>

using namespace std;

int _gcd(int a, int b, int &x, int &y) {
    //
    if (b > a) {
        return _gcd(b, a, x, y);
    }

    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    }

    int res = _gcd(b, a % b, x, y); 
    int temp = x; 
    x = y;
    y = temp - (a / b) * y;

    return res;
}

int main() {

    int a = 0, b = 0;
    cout << _gcd(29, 13, a, b) << '\n';
    cout << b << '\n';

    return 0;

}
