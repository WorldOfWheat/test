#include <bits/stdc++.h>
#define MOD (int) 420

using namespace std;

int sum = 0;

void dfs(int start_number, int length_now, int total_length)
{
    if (length_now == total_length) 
    {
        sum++;
        return;
    }

    for (int i = start_number; i <= 9; i++)
    {
        dfs(i, length_now + 1, total_length);
    }
}

int main()
{
    int n = 10, m = 1;
    string str = "17";

    dfs(str.back() - '0', m, n);
    cout << sum << '\n';

    return 0;
}
