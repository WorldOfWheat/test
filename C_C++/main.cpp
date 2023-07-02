#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

<<<<<<< HEAD
int n;
set<ll> se;
set<ll> se2;

void solve() 
{
	cin >> n;
	ll sum = (1 + n) * n / 2;
	if (sum % 2)
	{
		cout << "NO" << '\n';
		return;
=======
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
>>>>>>> b39827bfdcedd0358399f07b0b28ac74cf4406e4
	}
	cout << "YES" << '\n';
	ll mid = sum / 2;
	ll sum2 = 0;
	for (int i = 1; i <= n; i++)
	{
		se.insert(i);
	}

	ll diff = mid - sum2;
	while (diff != 0)
	{
		auto lower = se.lower_bound(diff);
		if (lower == se.end())
		{
			lower = prev(lower);
		}
		se2.insert(*lower);
		se.erase(lower);
		sum2 += *lower;
		sum -= *lower;
		diff = mid - sum2;
	}

	cout << (se.size()) << '\n';
	for (auto i : se)
	{
		cout << i << ' ';
	}
	cout << '\n';
	cout << (se2.size()) << '\n';
	for (auto i : se2)
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
