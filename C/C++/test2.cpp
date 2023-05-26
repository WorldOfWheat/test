#include <bits/stdc++.h>

using namespace std;

int SearchLowerBound(int x)
{
    int result = 0;
    while (((1 << result) - result - 1) < x)
    {
        result++;
    }

    return result;
}

signed main() 
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);


    return 0;
}