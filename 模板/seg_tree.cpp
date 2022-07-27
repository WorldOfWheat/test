
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

class seg_tree {
    public:
        seg_tree(int x) {
            data.resize(4*x);
        }
        void build (vector<int> x) {
            _size = x.size();
            input.resize(_size);
            copy(x.begin(), x.end(), input.begin());
            build(1, _size, 1);
        }
        int query(int x) {
            query(x, x);
        }
        int query(int l, int r) {
            return query(l, r, 1, _size, 1);
        }
    private:
        vector<int> input;
        vector<int> data;
        int _size;
        int lc(int x) {
            return (x*2);
        }
        int rc(int x) {
            return (x*2+1);
        }
        void build(int l, int r, int x) {
            if (l == r) {
                data[x] = input[l];
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, lc(x));
            build(mid+1, r, rc(x));
            data[x] = data[lc(x)] + data[rc(x)];
        }
        int query(int l, int r, int l2, int r2, int x) {
            if (l == l2 && r == r2) {
                return data[x];
            }
            int sum = 0;
            int mid = (l2 + r2) / 2;
            if (r <= mid) {
                sum += query(l, r, l2, mid, lc(x));
            }
            else if (l > mid) {
                sum += query(l, r, mid+1, r2, rc(x));
            }
            else {
                sum += query(l, mid, l2, mid, lc(x)) + query(mid+1, r, mid+1, r2, rc(x));
            }
            return sum;
        }
};

vector<int> ve = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void solve() {

    seg_tree seg(ve.size());
    seg.build(ve);
    cout << (seg.query(1, 9)) << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

