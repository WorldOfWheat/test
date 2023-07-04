#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;
int n;

ll fast_pow(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	if (y == 1)
	{
		return x;
	}

	ll k = fast_pow(x, y / 2) % MOD;
	if (y % 2)
	{
		return x * k * k % MOD;
	}
	return k * k % MOD;
}

void solve() 
{
	cin >> n;
	cout << (fast_pow(2, n)) << '\n';
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}