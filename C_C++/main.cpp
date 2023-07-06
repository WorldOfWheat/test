#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string str;

void solve() 
{
	cin >> str;
	int counter = 0;
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0)
		{
			counter = 1;
			ans = 1;
			continue;
		}
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