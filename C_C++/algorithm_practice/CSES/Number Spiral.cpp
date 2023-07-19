#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int t;

void solve() 
{
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		ll maxi = max(n, m);
		ll square = maxi * maxi;
		ll spiral_number = square - (maxi - 1);
		// printf("# %d %d %d\n", maxi, square, spiral_number);
		if (maxi & 1)
		{
			if (n > m)
			{
				cout << (spiral_number - (maxi - m)) << '\n';
			}
			else
			{
				cout << (spiral_number + (maxi - n)) << '\n';
			}
		}
		else
		{
			if (n > m)
			{
				cout << (spiral_number + (maxi - m)) << '\n';
			}
			else
			{
				cout << (spiral_number - (maxi - n)) << '\n';
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
