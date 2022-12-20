#include <bits/stdc++.h>

using namespace std;

string str = "FEKHFM";
string str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

map<char, int> ma;
map<int, char> ma2;

int exgcd(int a, int b, int &x, int &y) {
    //b % a 的模逆元為 y

    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    }

    int res = exgcd(b, a % b, x, y); 
    int temp = x; 
    x = y;
    y = temp - (a / b) * y;

    return res;
}

int main() {
   
    for (int i = 0; i < str2.length(); i++) {
        ma[str2[i]] = i;
        ma2[i] = str2[i];
    }


    for (int o = 0; o < str.length(); o += 1) {
        int k = ma[str[o]];

        int a, b;
        exgcd(26, 17, a, b);
        if (b < 0) {
            b = (26 + b) % 26;
        }

        int k2 = (b * (k - 20)) % 26;
        if (k2 < 0) {
            k2 += 26;
        }
        cout << (ma2[k2]);
    }

    return 0;

    for (int i = 1; i <= 29; i++) {
        for (int j = 1; j <= 29; j++) {
            stringstream ss;
            for (int o = 0; o < str.length(); o += 1) {
                int k = ma[str[o]];

                int a, b;
                exgcd(26, i, a, b);

                int k2 = b - (k - j) % 29;
                cout << ((char) (k2 / 29));
            } 
        }
    }

    return 0;

}
