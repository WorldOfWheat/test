#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n / 100 + (n % 100 > 0) << '\n';

    return 0;
}