#include <bits/stdc++.h>
#define pii pair<int, int> 

typedef long long ll;

using namespace std;

int n, m;
int k;
stringstream ss;

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
	for (int q = 1; q <= 30; q++)
	{
		cout << q << endl;
		//
		//init
		ss.str("");
		ss.clear();
		//
		ifstream ifs;
		ifs.open("D:\\tests\\example_" + to_string(q) + ".txt");
		if (ifs.fail())
		{
			cout << "Fail" << '\n';
		}

		ifs >> n >> m;
		string str[n];
		for (int i = 0; i < n; i++)
		{
			ifs >> str[i];
		}

		ifs >> k;
		int index = 0;
		bool is_get = false;
		for (int i = 0; i < k; i++)
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
				p.first--;
				p.second--;
				is_get = str[p.first][p.second] == '#';
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
				if (is_get)
				{
					pii p = get_row_column(index, n, m);
					p.first--;
					p.second--;
					bool if_can_put = true;
					for (int j = -1; j <= 1; j++)
					{
						if (p.second + j < 0 || p.second + j >= m)
						{
							if_can_put = false;
							break;
						}
						if (p.first - 1 < 0 || str[p.first - 1][p.second + j] != '-')
						{
							if_can_put = false;
							break;
						}
						if (str[p.first][p.second + j] != '-')
						{
							if_can_put = false;
							break;
						}
						if (p.first + 1 >= n || str[p.first + 1][p.second + j] != '-')
						{
							if_can_put = false;
							break;
						}
					}
					if (!if_can_put)
					{
						ss << "collision" << '\n';
						continue;
					}

					for (int j = -1; j <= 1; j++)
					{
						str[p.first - 1][p.second + j] = '*';
						str[p.first][p.second + j] = '*';
						str[p.first + 1][p.second + j] = '*';
					}
					str[p.first][p.second] = '#';
					ss << "put successful" << '\n';
					is_get = false;
				}
				else 
				{
					ss << "put nothing" << '\n';
				}
			}
		}

		ofstream ofs;
		ofs.open("D:\\tests\\a" + to_string(q) + ".txt");
		if (ofs.fail())
		{
			cout << "Fail" << '\n';
		}

		ofs << ss.str();
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