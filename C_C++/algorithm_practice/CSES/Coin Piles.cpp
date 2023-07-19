#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;

void solve() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		int o = (2 * a - b);
		int p = (2 * b - a);
		bool bo1 = (o % 3 == 0 && p % 3 == 0);
		bool bo2 = (o >= 0 && p >= 0);
		if (bo1 && bo2)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
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