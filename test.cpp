#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m;
vector<int> ve;

class seg_tree {
    public:
        seg_tree(vector<int> x) {
            _size = x.size();
            input.resize(_size);
            copy(x.begin(), x.end(), input.begin());
            data.resize(_size*4);
            data2.resize(_size*4);
            build(1, _size, 1);
        }
        int query(int l, int r) {
            return query(l, r, 1, _size, 1);
        }
        int query_maxi(int l, int r) {
            return query_maxi(l, r, 1, _size, 1);
        }

    private:
        int _size;
        vector<int> input;
        vector<int> data;
        vector<int> data2;
        int lc(int x) {
            return (2*x);
        }
        int rc(int x) {
            return (2*x+1);
        }
        void build(int l, int r, int x) {
            if (l == r) {
                data[x] = input[l];
                data2[x] = input[l] % m;
                //cout << data2[x] << endl;
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, lc(x));
            build(mid+1, r, rc(x));
            data[x] = data[lc(x)] + data[rc(x)];

            int a = (data2[lc(x)] + data2[rc(x)]) % m;
            int b = data2[lc(x)] % m;
            int c = data2[rc(x)] % m;

            data2[x] = max({a, b, c});
        }
        int query(int l, int r, int l2, int r2, int x) {
            //cout << l << " " << r << " " << l2 << " " << r2 << " " << x << endl;
            if (l == l2 && r == r2) {
                return data[x];
            }
            int mid = (l2 + r2) / 2;
            int sum = 0;
            if (r <= mid) {
                sum += query(l, r, l2, mid, lc(x));
            }
            else if (l > mid) {
                sum += query(l, r, mid+1, r2, rc(x));
            }
            else {
                int a = query(l, mid, l2, mid, lc(x));
                int b = query(mid+1, r, mid+1, r2, rc(x));
                sum += a + b;
            }
            return sum;
        }
        int query_maxi(int l, int r, int l2, int r2, int x) {
            //cout << l << " " << r << " " << l2 << " " << r2 << " " << x << endl;
            if (l == l2 && r == r2) {
                //cout << data2[x] << endl;
                return data2[x];
            }
            int mid = (l2 + r2) / 2;
            int maxi = -1e18;
            if (r <= mid) {
                int a = query_maxi(l, r, l2, mid, lc(x));
                //cout << a << endl;
                maxi = max(maxi, a);
            }
            else if (l > mid) {
                int a = query_maxi(l, r, mid+1, r2, rc(x));
                //cout << a << endl;
                maxi = max(maxi, a);
            }
            else {
                int a = query_maxi(l, mid, l2, mid, lc(x));
                int b = query_maxi(mid+1, r, mid+1, r2, rc(x));
                //cout << a << " " << b << endl;
                maxi = max({maxi, a, b, (a+b) % m});
            }
            return maxi;
        }

};

void solve() {

    cin >> n >> m;
    ve.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    seg_tree seg(ve);
    cout << ( seg.query_maxi(1, n) ) << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
