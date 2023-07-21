#include <bits/stdc++.h>
#define pii pair<int, int>

typedef long long ll;

using namespace std;


void solve()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		ll m;
		cin >> n >> m;
		vector<ll> ve(n);
		for (auto &i : ve)
		{
			cin >> i;
		}

		if (n == 1)
		{
			cout << 0 << '\n';
			continue;
		}

		sort(ve.begin(), ve.end());

		int maximum = INT_MIN;
		int count = 1;
		for (int i = 1; i < n; i++)
		{
			int remain = ve[i] - ve[i-1];
			if (abs(remain <= m))
			{
				count++;
			}
			else
			{
				count = 1;
			}

			maximum = max(maximum, count);
		}
		cout << n - (maximum) << endl;
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}