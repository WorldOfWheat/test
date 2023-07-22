#include <bits/stdc++.h>
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int n;
ll m;
vector<ll> ve;

int test(ll x)
{
	ll sum = 0;
	for (auto i : ve)
	{
		sum += (i + 2ll * x) * (i + 2ll * x);
	}

	if (sum < m)
	{
		return -1;
	}
	if (sum > m)
	{
		return 1;
	}
	return 0;
}

ll binary_search()
{
	if (test(0) == 0)
	{
		return 0;
	}

	ll res = 0;
	ll i;
	for (i = ((ll) 2e5) >> 1ll; i > 0; i >>= 1ll)
	{
		while (test(res + i) == -1 || test(res + i) == 0)
		{
			res += i;
		}
	}
	
	return res;
}

void solve()
{
	int t;
	cin >> t;
	while (t--)
	{
		ve.clear();

		cin >> n >> m;
		ve.resize(n);
		for (auto &i : ve)
		{
			cin >> i;
		}

		cout << (binary_search()) << '\n';
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}