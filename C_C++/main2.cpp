#include <bits/stdc++.h>
#define pii pair<int, int> 

typedef long long ll;

using namespace std;

int n, m;
int k;

int string_to_int(string str)
{
	int result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		result *= 10;
		result += str[i] - '0';
	}

	return result;
}

pii get_row_column(int index, int height, int width)
{
	int row = 1;
	while (row * width < index)
	{
		row++;
	}
	int column = index - (row - 1) * width;

	return make_pair(row, column);
}

void solve() 
{
	ifstream ifs;
	ifs.open("D:\\tests\\1.txt");
	if (ifs.fail())
	{
		cout << "Fail" << '\n';
	}

	ifs >> n >> m;
	string str[n];
	for (int i = 0; i < n; i++)
	{
		ifs >> str[i];
		str[i] += '\n';
	}

	ifs >> k;
	int index = 0;
	bool is_get = false;
	for (int i = 0; i < k; k++)
	{
		string command;
		ifs >> command;
		if (command == "ptp")
		{
			string point;
			ifs >> point;
			index = string_to_int(point.substr(1));
		}
		else if (command == "get")
		{
			pii p = get_row_column(index, n, m);
			is_get = str[p.first][p.second] = '#';
			if (is_get)
			{
				for (int j = -1; j <= 1; j++)
				{
					str[p.first - 1][p.second + j] = '-';
					str[p.first][p.second + j] = '-';
					str[p.first + 1][p.second + j] = '-';
				}
			}
		}
		else 
		{
			pii p = get_row_column(index, n, m);
			bool if_can_put = true;
			for (int j = -1; j <= 1; j++)
			{
				if (str[p.first - 1][p.second + j] != '-')
				{
					if_can_put = false;
				}
				if (str[p.first][p.second + j] != '-')
				{
					if_can_put = false;
				}
				if (str[p.first + 1][p.second + j] != '-')
				{
					if_can_put = false;
				}
			}
			if (!if_can_put)
			{
				cout << "collision" << '\n';
				continue;
			}

			for (int j = -1; j <= 1; j++)
			{
				str[p.first - 1][p.second + j] = '*';
				str[p.first][p.second + j] = '*';
				str[p.first + 1][p.second + j] = '*';
				str[p.first][p.second] = '#';
			}
			cout << "put successful" << '\n';
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