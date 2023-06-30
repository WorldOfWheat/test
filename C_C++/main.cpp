#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
vector<vector<bool>> checked;

vector<pair<int, int>> getCoordinates(int graph_size, pair<int, int> coordinate)
{
	vector<pair<int, int>> res;
	int x = coordinate.first;
	int y = coordinate.second;
	if (x - 2 >= 0 && y - 1 >= 0)
	{
		res.push_back({x - 2, y - 1});
	}
	if (x - 2 >= 0 && y + 1 < graph_size)
	{
		res.push_back({x - 2, y + 1});
	}
	if (x - 1 >= 0 && y - 2 >= 0)
	{
		res.push_back({x - 1, y - 2});
	}
	if (x - 1 >= 0 && y + 2 < graph_size)
	{
		res.push_back({x - 1, y + 2});
	}
	if (x + 2 < graph_size && y - 1 >= 0)
	{
		res.push_back({x + 2, y - 1});
	}
	if (x + 2 < graph_size && y + 1 < graph_size)
	{
		res.push_back({x + 2, y + 1});
	}
	if (x + 1 < graph_size && y - 2 >= 0)
	{
		res.push_back({x + 1, y - 2});
	}
	if (x + 1 < graph_size && y + 2 < graph_size)
	{
		res.push_back({x + 1, y + 2});
	}

	return res;
}

int fun(int graph_size, pair<int, int> coordinate)
{
	ll res = 0;
	for (int i = 0; i < graph_size; i++)
	{
		for (int j = 0; j < graph_size; j++)
		{
			if (checked[i][j])
			{
				continue;
			}

			res++;
		}
	}

	return res;
}

void solve() 
{
	// for (auto i : getCoordinates(6, {3, 3}))
	// {
	// 	cout << i.first << ' ' << i.second << '\n';
	// }
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		ll ans = 0;
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < i; k++)
			{
				checked.clear();
				checked.resize(n, vector<bool>(n, 0));
				checked[j][k] = 1;
				for (auto l : getCoordinates(i, {j, k}))
				{
					checked[l.first][l.second] = 1;
				}
				ans += fun(i, {j, k});
			}
		}
		cout << ans/2 << '\n';
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
