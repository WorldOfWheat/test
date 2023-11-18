#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    for (int i = 0; i < 52; i++)
    {
        if (i % 4 == i % 13) cout << i << ' ';
    }

    return 0;
}
