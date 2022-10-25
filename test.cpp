#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define sp " "
#define ln "\n"

using namespace std;

int a, b;

void solve() {
    
	a = 50000000;
	b = 2500005;
	
	cout << a << sp << b << ln;

	int c = a ^ b;
	a ^= c;
	b ^= c;

	cout << a << sp << b << ln;

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
