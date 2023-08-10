#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
int ans;
stringstream ss;

void dfs(int x, int y, int z, int count)
{
	if (count == 1)
	{
		ss << x << ' ' << z << '\n';
		ans++;
		return;
	}

	dfs(x, z, y, count-1);
	ss << x << ' ' << z << '\n';
	ans++;
	dfs(y, x, z, count-1);
}

void solve()
{
	cin >> n;
	dfs(1, 2, 3, n);
	cout << ans << '\n' << (ss.str()) << '\n';
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}