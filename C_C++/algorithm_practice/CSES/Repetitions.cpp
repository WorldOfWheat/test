#include <bits/stdc++.h>

using namespace std;

string str;

void solve() 
{
	cin >> str;
	int ans = 1;
	int counter = 1;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i-1])
		{
			counter++;
		}
		else
		{
			counter = 1;
		}
		ans = max(ans, counter);
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
