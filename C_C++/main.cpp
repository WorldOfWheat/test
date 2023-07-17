#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() 
{
	int n = 5, m = 7;
	int index = 7;
	int x = (index / m) + 1;
	int y = (index % m) + 1;
	cout << x << ' ' << y << '\n';
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}