#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x;
    int y;
};

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<vector<int>> world;
vector<vector<int>> visited;
queue<Point> bfs;
Point player;
Point door;
int n, m;
int k;

void solve() 
{
    cin >> n >> m;
    world.resize(n, vector<int>(m));
    cin >> player.x >> player.y;
    cin >> door.x >> door.y;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        world[x][y] = 100;
    }

    bfs.push(player);
    visited[player.x][player.y] = 1;
    while (bfs.size())
    {
        cout << bfs.size() << '\n';
        Point top = bfs.front();
        bfs.pop();

        if (top.x == door.x && top.y && door.y)
        {
            cout << "Cool!" << '\n';
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            Point next;
            next.x = player.x + dx[i];
            next.y = player.y + dy[i];
            if (!(next.x >= 0 && next.x < n))
            {
                continue;
            }
            if (!(next.y >= 0 && next.y < m))
            {
                continue;
            }
            if (world[next.x][next.y] == 100)
            {
                continue;
            }
            if (visited[next.x][next.y] == 1)
            {
                continue;
            }

            visited[next.x][next.y] = 1;
            bfs.push(next);
        }
    }

    cout << "Harakiri!" << '\n';
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}