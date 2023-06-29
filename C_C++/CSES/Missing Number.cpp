#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> arr;

void solve() 
{
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		int k;
		cin >> k;
		arr[k-1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			cout << i + 1;
		}
	}
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
