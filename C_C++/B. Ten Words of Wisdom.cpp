#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


void solve()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		int ans = 1;
		int maximum = INT32_MIN;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a > 10)
			{
				continue;
			}
			if (b > maximum)
			{
				ans = i + 1;
				maximum = b;
			}
		}
		cout << ans << '\n';
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}