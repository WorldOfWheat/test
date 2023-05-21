#include <bits/stdc++.h>


using namespace std;

int add(int a, int b)
{
    int carry = 0;
    int sum = 0;
    int i;
    for (i = 1; i <= max(a, b); i <<= 1)
    {
        sum |= (a & i) ^ (b & i) ^ (carry & i); 
        carry = (((a & b & i) | (a & carry & i) | (b & carry & i)) << 1);
    }
    if (carry > 0)
    {
        sum |= carry;
    }

    return sum;
}

void solve() 
{
    int a, b;
    cin >> a >> b;
    cout << (add(a, b));
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}