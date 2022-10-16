#include <bits>
#define ln "\n"
#define sp " "

using namespace std;

int main() {

    int a;
    cin >> a;

    cout << (a % 12 * 5 + a / 12 * 50);

    return 0;

}