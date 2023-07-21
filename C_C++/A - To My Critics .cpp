#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> ve(3);

void solve()
{
	int q;
	cin >> q;
	while (q--)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> ve[i];
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				if (ve[i] + ve[j] >= 10)
				{
					cout << "yes" << '\n';
					goto skip;
				}
			}
		}
		cout << "no" << '\n';
		skip:
		continue;
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}