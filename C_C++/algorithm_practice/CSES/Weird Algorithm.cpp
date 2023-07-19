#include <bits/stdc++.h>

using namespace std;

int n;

void dfs(long long x)
{
	cout << x << ' ';
	if (x == 1)
	{
		return;
	}

	if (x % 2)
	{
		dfs(3 * x + 1);
	}
	else
	{
		dfs(x / 2);
	}
}

void solve() 
{
	cin >> n;
	dfs(n);
	cout << '\n';
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}
