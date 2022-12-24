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
#define INF (int) 1e18
#define ln '\n'

using namespace std;

int n, m;
<<<<<<< HEAD
V ve;
=======
set<int> se;
multiset<int> ms;
>>>>>>> afcfd5c6542d89e24fa7b91167f7cd98496cb515

void solve() {

    cin >> n >> m;

<<<<<<< HEAD
    ve.resize(n);
    rep (i, 0, n) {
        int in;
        cin >> in;
=======
    se.insert(0);
    se.insert(n);
    ms.insert(n);

    rep (i, 0, m) {
        int in;
        cin >> in;

        auto it = prev(se.lower_bound(in));
        auto it2 = se.lower_bound(in);
        int k = *it2 - *it;

        ms.erase(ms.lower_bound(k));

        int middleToLeft = in - (*it);
        int middleToRight = (*it2) - in;

        se.insert(in);
        ms.insert(middleToLeft);
        ms.insert(middleToRight);

        cout << *(ms.rbegin()) << ln;

    }
>>>>>>> afcfd5c6542d89e24fa7b91167f7cd98496cb515

        ve[--in] = i;
    }

    int ans = 1;
    rep (i, 1, n) {
        if (ve[i] <= ve[i-1]) {
            ans++; 
        }
    }

    rep (i, 0, m) {
        int in, in2;
        cin >> in >> in2;
        in--;
        in2--;
        
        int a = 0;
        if (in2 + 1 < n) {
            if (ve[in2] < ve[in2 + 1]) {
                a++;
            }
            else {
                a--;
            }
        }
        if (in - 1 >= 0) {
            if (ve[in - 1] < ve[in]) {
                a++;
            }
            else {
                a--;
            }
        }

        swap(ve[in], ve[in2]);

        int b = 0;
        if (in2 + 1 < n) {
            if (ve[in2] < ve[in2 + 1]) {
                b++;
            }
            else {
                b--;
            }
        }
        if (in - 1 >= 0) {
            if (ve[in - 1] < ve[in]) {
                b++;
            }
            else {
                b--;
            }
        }

        int diff = a - b;

        cout << a << ' ' << b << ' ' << diff << ln;
    }

    cout << ans << ln;
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;

}

