#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (!(1 <= n && n <= 12)) {
            cout << "請重新輸入" << '\n';       
            continue;
        }
        if (1 <= n && n <= 3) {
            cout << "春\n";
        }
        if (4 <= n && n <= 6) {
            cout << "夏\n";
        }
        if (7 <= n && n <= 9) {
            cout << "秋\n";
        }
        if (10 <= n && n <= 12) {
            cout << "冬\n";
        }
    }
    return 0;
}