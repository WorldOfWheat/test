#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;


int column;
vector<string> graph(8, "");
vector<pii> checked;
int ans;

bool check(pii coordinate)
{
    if (column & 1 << coordinate.second)
    {
        return false;
    }
    
    for (int i = 0; i < checked.size(); i++)
    {
        if (abs(checked[i].first - coordinate.first) == abs(checked[i].second - coordinate.second))
        {
            return false;
        }
    }

    if (graph[coordinate.first][coordinate.second] == '*')
    {
        return false;
    }

    return true;
}

void dfs(int count)
{
    if (count == 8)
    {
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (!check({count, i}))
        {
            continue;
        }

        column |= (1 << i);
        checked.push_back({count, i});

        dfs(count + 1);

        column &= ~(1 << i);
        checked.pop_back();
    }
}

void solve()
{
    for (int i = 0; i < 8; i++)
    {
        cin >> graph[i];
    }

    dfs(0);

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