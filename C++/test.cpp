#include <bits/stdc++.h>

using namespace std;

int n;

string getGray(string x)
{
    string result = "1";
    for (int i = 1; i < x.length(); i++) 
    {
        if (x[i - 1] != x[i]) 
        {
            result += '1';
        }
        else
        {
            result += '0';
        }
    }

    return result;
}

string getBinary(int x) 
{
    string result = "";
    while (x > 0) 
    {
        if (x & 1) 
        {
            result += "1";
        }
        else
        {
            result += "0";
        }

        x >>= 1;
    }

    reverse(result.begin(), result.end());

    return result;
}

void solve() 
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "0";
    }
    cout << '\n';

    for (int i = 1; i <= (1 << n) - 1; i++) 
    {
        cout << right << fixed << setw(n) << setfill('0') << (getGray(getBinary(i))) << '\n';
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}