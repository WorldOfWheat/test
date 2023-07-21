#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


void solve()
{
	int q;
	cin >> q;
	while (q--)
	{
		vector<string> ve(8);
		for (int i = 0; i < 8; i++)
		{
			cin >> ve[i];
		}

		stringstream ss;
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (ve[i][j] != '.')
				{
					ss << ve[i][j];
				}
			}
		}

		cout << ss.str() << '\n';
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}