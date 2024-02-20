#include <iostream>

using namespace std;

bool test() {
    cout << "This is true" << '\n';
    return true;
}

int main()
{
    if (test() || 1) {
        cout << boolalpha << 1;
    }
    else {
        cout << boolalpha << 0;
    }

    return 0;
}