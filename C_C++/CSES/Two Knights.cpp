#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;

void solve() 
{
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cout << (((i * i) * ((i * i) - 1)) / 2) << ' ' << ((2 * (i - 1) * (i - 2)) + (2 * (i - 1) * (i - 2))) << '\n';
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
