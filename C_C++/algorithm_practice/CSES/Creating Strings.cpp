#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string str;
int ans;
stringstream ss;

void solve()
{
	cin >> str;
	
	sort(str.begin(), str.end());

	do 
	{
		ss << str << '\n';
		ans++;
	} while (next_permutation(str.begin(), str.end()));

	cout << ans << '\n' << ss.str() << '\n';
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}