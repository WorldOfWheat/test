#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string str;
map<char, int> ma;

void solve() 
{
	cin >> str;
	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		ma[str[i]]++;
	}

	int counter = 0;
	for (int i = 0; i < 26; i++)
	{
		if (ma[i + 'A'] % 2 == 1)
		{
			counter++;
		}
	}
	if (counter >= 2)
	{
		cout << "NO SOLUTION" << '\n';
		return;
	}

	string prefix = "";
	string suffix = "";
	string mid = "";
	for (int i = 0; i < 26; i++)
	{
		int count = ma[i + 'A'];
		char k = i + 'A';
		if (count % 2)
		{
			for (int j = 0; j < count; j++)
			{
				mid += k;
			}
			continue;
		}
		for (int j = 0; j < count / 2; j++)
		{
			prefix += k;
			suffix += k;
		}
	}
	reverse(suffix.begin(), suffix.end());
	string ans = prefix + mid + suffix;

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