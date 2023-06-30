#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

void solve() 
{
	cin >> n;
	if (n == 1)
	{
		cout << "1" << '\n';
		return;
	}

	arr.resize(n);
	int counter = 0;
	for (int i = 2; i <= n; i += 2)
	{
		arr[counter++] = i;
	}

	if (abs(arr[counter - 1] - 1) <= 1)
	{
		cout << "NO SOLUTION" << '\n';
		return;
	}

	for (int i = 1; i <= n; i += 2)
	{
		arr[counter++] = i;
	}
	for (auto i : arr)
	{
		cout << i << ' ';
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
