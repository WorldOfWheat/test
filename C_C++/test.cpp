#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 7; // 111
    n &= ~(1 << 1);
    cout << n << '\n';
    
    return 0;
}