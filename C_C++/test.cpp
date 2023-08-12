#include <bits/stdc++.h>
#define ll long long

using namespace std;

const vector<int> offset_x = {1, -1, 0, 0};
const vector<int> offset_y = {0, 0, 1, -1};
string str;
vector<vector<bool>> visited(7 + 2, vector<bool>(7 + 2));
ll ans;

void dfs(int x, int y, int count)
{
    cout << x << ' ' << y << ' ' << count << endl;
    if (x == 7 && y == 1)
    {
        ans = count == 48;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int dx = offset_x[i] + x;
        int dy = offset_y[i] + y;

        if (visited[dx][dy])
        {
            continue;
        }

        visited[dx][dy] = true;
        dfs(dx, dy, count + 1);
        visited[dx][dy] = false;
    }
}

void solve()
{
    // cin >> str;
    for (int i = 0; i < 9; i++)
    {
        visited[i][0] = true;
        visited[0][i] = true;
        visited[i][8] = true;
        visited[8][i] = true;
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cout << visited[i][j];
    //     }
    //     cout << '\n';
    // }

    visited[1][1] = true;
    dfs(1, 1, 1);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    
    return 0;
}