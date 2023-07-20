#include <iostream>
#include <string>

using namespace std;

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

int get_row(int index, int width)
{
	int row = 1;
	while (row * width < index)
	{
		row++;
	}
	return row;
}

int get_column(int index, int row, int width)
{
	int column = index - ((row - 1) * width);
	return column;
}

int main() 
{
	int n, m;
	cin >> n >> m;

	string str[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	
	int k;
	cin >> k;
	string cmd;
	int row, column;
	bool is_grep = false;
	for (int i = 0; i < k; i++)
	{
		cin >> cmd;
		if (cmd == "ptp")
		{
			cin >> cmd;
			cmd = cmd.substr(1);
			int index = string_to_int(cmd);
			row = get_row(index, m);
			column = get_column(index, row, m);
			row--, column--;
		}
		else if (cmd == "get")
		{
			if (str[row][column] == '#')
			{
				is_grep = true;
				for (int j = -1; j <= 1; j++)
				{
					str[row - 1][column + j] = '-';
					str[row][column + j] = '-';
					str[row + 1][column + j] = '-';
				}
			}
			else
			{
				is_grep = false;
			}
		}
		else
		{
			if (!is_grep)
			{
				cout << "put nothing" << '\n';
			}
			else
			{
				bool if_can_put = true;
				for (int j = -1; j <= 1; j++)
				{
					if (column + j < 0 || column + j >= m)
					{
						if_can_put = false;
						break;
					}
					if (row - 1 < 0 || str[row - 1][column + j] != '-')
					{
						if_can_put = false;
						break;
					}
					if (str[row][column + j] != '-')
					{
						if_can_put = false;
						break;
					}
					if (row + 1 >= n || str[row + 1][column + j] != '-')
					{
						if_can_put = false;
						break;
					}
				}
				if (!if_can_put)
				{
					cout << "collision" << '\n';
				}
				else
				{
					for (int j = -1; j <= 1; j++)
					{
						str[row - 1][column + j] = '*';
						str[row][column + j] = '*';
						str[row + 1][column + j] = '*';
					}
					str[row][column] = '#';
					cout << "put successful" << '\n';
					is_grep = false;
				}
			}
		}
	}

	return 0;
}