#include <bits/stdc++.h>
<<<<<<< HEAD
#include <ranges> 

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int a = (int) 'a';
    cout << a << '\n';
    cout << oct << a << '\n';
    cout << hex << a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
=======
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define b2e(x) x.begin(), x.end()
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define INF (int) 1e18

using namespace std;

int n;
VP arr;

void solve() 
{
    cin >> n;
    arr.resize(n);
    for (auto &i : arr) {
        cin >> i.F >> i.S;
    }
    
    sort(b2e(arr));

    
}

signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	solve();

	return 0;
}
>>>>>>> 9749cab (Add new algorithm practice)
