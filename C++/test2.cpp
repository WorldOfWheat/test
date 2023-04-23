#include <bits/stdc++.h>

using namespace std;

int n;
string numbers;

void rotate(string &input, int begin, int end)
{
    input = input.substr(end - 1, 1) + input.substr(begin, end - begin - 1) + input.substr(end, input.length());
}

void dfs(int depth)
{
    if (depth == numbers.length())
    {
        for (auto i : numbers)
        {
            cout << i << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = depth; i < numbers.length(); i++) 
    {
        cerr << "#" << i << ' ' << depth << '\n';
        rotate(numbers, depth, i + 1);
        dfs(depth + 1);
        rotate(numbers, depth, i + 1);
    }
}

void solve() 
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        numbers.append(to_string(i));
    }

    dfs(0);
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}