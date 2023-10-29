#include <bits/stdc++.h>

using namespace std;

int t;

int main() 
{
    cin >> t;
    while (t--) 
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        printf("%d %d %d %d ", a, b, c, d);
        if (d - c == b - a) {
            cout << (d + d - c) << '\n';
        } 
        else {
            cout << (d * (b / a)) << '\n';
        }
    }
    
    return 0;
}