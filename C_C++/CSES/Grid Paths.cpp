#include <bits/stdc++.h>

using namespace std;

const int offset_x[4] = {1, -1, 0, 0};
const int offset_y[4] = {0, 0, 1, -1};
string str;
bool visited[7+2][7+2];
int ans;

bool check(int x, int y)
{
    if (visited[x][y])
    {
        return false;
    }
    if (visited[x - 1][y] && visited[x + 1][y] && (!visited[x][y - 1] && !visited[x][y + 1]))
    {
        return false;
    }
    if (visited[x][y - 1] && visited[x][y + 1] && (!visited[x - 1][y] && !visited[x + 1][y]))
    {
        return false;
    }
    return true;
}

void dfs(int x, int y, int count)
{
    if (x == 7 && y == 1)
    {
        ans += count == 48;
        return;
    }

    visited[x][y] = true;
    if (str[count] == '?')
    {
        for (int i = 0; i < 4; i++)
        {
            int dx = offset_x[i] + x;
            int dy = offset_y[i] + y;

            if (!check(dx, dy))
            {
                continue;
            }

            visited[dx][dy] = true;
            dfs(dx, dy, count + 1);
            visited[dx][dy] = false;
        }
    }
    else
    {
        int dx, dy;
        switch (str[count])
        {
        case 'U':
            dx = x + offset_x[1];
            dy = y + offset_y[1];
            break;
        case 'D':
            dx = x + offset_x[0];
            dy = y + offset_y[0];
            break;
        case 'L':
            dx = x + offset_x[3];
            dy = y + offset_y[3];
            break;
        case 'R':
            dx = x + offset_x[2];
            dy = y + offset_y[2];
            break;
        }

        if (!check(dx, dy))
        {
            return;
        }

        visited[dx][dy] = true;
        dfs(dx, dy, count + 1);
        visited[dx][dy] = false;
    }
    visited[x][y] = false;
}

void solve()
{
    cin >> str;
    for (int i = 0; i < 9; i++)
    {
        visited[i][0] = true;
        visited[0][i] = true;
        visited[i][8] = true;
        visited[8][i] = true;
    }

    dfs(1, 1, 0);

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