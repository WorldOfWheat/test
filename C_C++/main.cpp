#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() 
{
	constexpr int LENGTH = 5;
	int arr[LENGTH] = {10, 20, 30, 40, 50}; 
	cout << (*(*(&arr) + 3)) << '\n';
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}