#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;

string get_binary(int num, int digits)
{
	stringstream ss;
	while (num > 0)
	{
		if (num & 1)
		{
			ss << 1;
		}
		else
		{
			ss << 0;
		}
		num >>= 1;
	}

	string res = ss.str();
	int length = res.length();
	for (int i = 0; i < digits - length; i++)
	{
		ss << 0;
	}
	res = ss.str();

	reverse(res.begin(), res.end());

	return res;
}

string get_gray(string str)
{
	stringstream ss;
	ss << str[0];
	int length = str.length();
	for (int i = 1; i < length; i++)
	{
		ss << (str[i-1] - '0' ^ str[i] - '0');
	}

	return ss.str();
}

void solve()
{
	cin >> n;
	for (int i = 0; i < ((1 << (n + 1)) - 1); i++)
	{
		string binary = get_binary(i, n);
		binary = get_gray(binary);
		cout << (binary) << '\n';
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}