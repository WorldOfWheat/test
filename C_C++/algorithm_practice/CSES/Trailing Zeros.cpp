#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;

void solve() 
{
	cin >> n;
	int ans = 0;
	for (int i = 5; i <= n; i *= 5)
	{
		ans += n / i;
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