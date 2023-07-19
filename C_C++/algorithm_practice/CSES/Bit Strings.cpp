#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MOD = 1e9 + 7;
int n;

void solve() 
{
	cin >> n;
	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		ans <<= 1;
		ans %= MOD;
	}

	cout << ans << '\n';
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}