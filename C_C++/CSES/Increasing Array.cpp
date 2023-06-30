#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

void solve() 
{
	cin >> n;
	arr.resize(n);
	for (auto &i : arr)
	{
		cin >> i;
	}

	long long ans = 0;
	for (int i = 1; i < n; i++)
	{
		long long difference = arr[i-1] - arr[i];
		if (difference <= 0)
		{
			continue;
		}
		ans += difference;
		arr[i] += difference;
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