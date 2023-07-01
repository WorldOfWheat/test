#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() 
{
	int arr[5]; // Dangerous
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	// Dangerous
	for (int i = 1; i <= 5; i++)
	{
		cout << arr[i] << ' ';
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
