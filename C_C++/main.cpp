#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
vector<vector<bool>> checked;
vector<vector<bool>> checked2;

vector<pair<int, int>> getCoordinates(pair<int, int> coordinate)
{
	vector<pair<int, int>> res;
	int x = coordinate.first;
	int y = coordinate.second;
	res.push_back({x - 2, y - 1});
	res.push_back({x - 2, y + 1});
	res.push_back({x - 1, y - 2});
	res.push_back({x - 1, y + 2});
	res.push_back({x + 2, y - 1});
	res.push_back({x + 2, y + 1});
	res.push_back({x + 1, y - 2});
	res.push_back({x + 1, y + 2});

	return res;
}

int dfs(int graph_size, pair<int, int> coordinate, int count)
{
	if (count == 2)
	{
		return 1;
	}

	int res = 0;
	for (int i = 1; i <= graph_size; i++)
	{
		for (int j = 1; j <= graph_size; j++)
		{
			if (checked[i][j])
			{
				continue;
			}

			res += dfs(graph_size, {i, j}, count + 1);
		}
	}

	return res;
}

void solve() 
{
	cin >> n;
	checked.resize(n, vector<bool>(n));
	checked2.resize(n, vector<bool>(n));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= i; k++)
			{
				checked.clear();
				checked[i][k] = 1;
				for (auto l : getCoordinates({j, k}))
				{
					checked[l.first][l.second] = 1;
				}
				cout << dfs(i, {j, k}, 1) << '\n';
			}
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}
