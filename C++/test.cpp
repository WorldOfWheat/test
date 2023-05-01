#include <bits/stdc++.h>

using namespace std;

vector<bitset<16>> bsArray;

void solve() 
{
    bsArray.resize(5);
        for (int i = 0; i < (1 << 2); i++)
        {
            bsArray[i] = i;
            cout << (bsArray[i].to_string()) << '\n';
            cout << (bsArray[i][0]) << '\n';
            // for (int j = 1; j < 16; j++)
            // {
            //     bsArray[i][j] = bsArray[i][j-1] ^ bsArray[i][j];
            // }
        }

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}