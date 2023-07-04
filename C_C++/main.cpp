#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> offset_x = {1, -1, 0, 0};
vector<int> offset_y = {0, 0, 1, -1};
vector<vector<bool>> graph;
vector<vector<bool>> checked;

void print_graph()
{
	for (auto i : graph)
	{
		for (auto j : i)
		{
			cout << j;
		}
		cout << endl;
	}
	cout << endl;
}

ll dfs(int x, int y, int max_x, int max_y)
{
	if (x + 1 == max_x && y + 1 == max_y)
	{
		return 1;
	}

	int res = 0;
	for (int i = 0; i < 4; i++)
	{
		int dx = x + offset_x[i];
		int dy = y + offset_y[i];
		if (dx < 0 || dx >= max_x)
		{
			continue;
		}
		if (dy < 0 || dy >= max_y)
		{
			continue;
		}
		if (checked[dx][dy])
		{
			continue;
		}

		checked[dx][dy] = 1;
		res += dfs(dx, dy, max_x, max_y);
		graph[dx][dy] = 0;
		checked[dx][dy] = 0;
	}

	return res;
}

void solve() 
{
	graph.resize(7, vector<bool>(7));
	checked.resize(7, vector<bool>(7));
	checked[0][0] = 1;
	cout << dfs(0, 0, 6, 6) << '\n';
	checked[0][0] = 0;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    // cout.tie(0);

	solve();

	return 0;
}