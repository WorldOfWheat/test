#include <bits/stdc++.h>

using namespace std;

void solve() 
{
    int g = 5;
    int a = 20;
    int b = 30;
    int p = 23;
    int A = g;
    int B = g;
    for (int i = 0; i < a; i++) 
    {
        A *= g % p;
        A %= p;
    }
    for (int i = 0; i < b; i++) 
    {
        B *= g % p;
        B %= p;
    }

    cout << "A=" << A << " B=" << B << endl;

    int s_a = B;
    int s_b = A;
    for (int i = 0; i < a; i++) 
    {
        s_a *= B % p;
        s_a %= p;
    }
    for (int i = 0; i < b; i++)
    {
        s_b *= A % p;
        s_b %= p;
    }

    cout << "s_a=" << s_a << " s_b=" << s_b << endl;
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}