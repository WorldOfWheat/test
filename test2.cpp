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
int times = 1;

int max(int x, int y) {
    return x >= y ? x : y;
}

struct node {
    int sum, left, right, lc, rc;
    int maxi_pf, maxi_pf_left, maxi_pf_right, maxi_sf, maxi_sf_left, maxi_sf_right;
    int maxi_subarray, maxi_subarray_left, maxi_subarray_right;
};

class seg_tree {
    public:
        int ans[3];
        seg_tree(vector<int> x) {
            _size = x.size();
            data.resize(4*_size);
            input.assign(x.begin(), x.end());
            build(1, _size, 1);
        }
        void query(int l, int r) {
            query(l, r, 1);
        }
        void reset_ans(int x) {
            ans[0] = -2ll << 60;
            ans1[0] = ans2[0] = 0;
            ans1[1] = ans1[2] = ans2[1] = ans2[2] = x;
        }
    private:
        int _size;
        vector<int> input;
        vector<node> data;
        int ans1[3];
        int ans2[3];
        int getLc(int x) {
            return x << 1;
        }
        int getRc(int x) {
            return (x << 1) + 1;
        }
        void build(int l, int r, int x) {
            data[x].left = l;
            data[x].right = r;
            if (l == r) {
                data[x].sum = data[x].maxi_pf = data[x].maxi_sf = data[x].maxi_subarray = input[l];
                data[x].maxi_pf_left =
                data[x].maxi_pf_right =
                data[x].maxi_sf_left =
                data[x].maxi_sf_right =
                data[x].maxi_subarray_left =
                data[x].maxi_subarray_right = l;
                return;
            }
            int mid = (l + r) >> 1;
            build(l, mid, getLc(x));
            build(mid+1, r, getRc(x));

            data[x].lc = getLc(x);
            data[x].rc = getRc(x);

            pull(data[x], data[ data[x].lc ], data[ data[x].rc ]);
        }
        void pull(node &x, node &y, node &z) {
            x.sum = y.sum + z.sum;
            x.maxi_pf_left =
            x.maxi_pf_right =
            x.maxi_sf_left =
            x.maxi_sf_right =
            x.maxi_subarray_left =
            x.maxi_subarray_right = 2ll << 60;
            //pf
            x.maxi_pf = max(y.maxi_pf, y.sum + z.maxi_pf);
            if (x.maxi_pf == y.maxi_pf) {
                x.maxi_pf_left = y.maxi_pf_left;
                x.maxi_pf_right = y.maxi_pf_right;
            }
            if (x.maxi_pf == y.sum + z.maxi_pf) {
                if ( x.maxi_pf_left > y.left ||
                (x.maxi_pf_left == y.left
                && x.maxi_pf_right > z.maxi_pf_right)
                ) {
                    x.maxi_pf_left = y.left;
                    x.maxi_pf_right = z.maxi_pf_right;
                }
            }

            //sf
            x.maxi_sf = max(z.maxi_sf, z.sum + y.maxi_sf);
            if (x.maxi_sf == z.maxi_sf) {
                x.maxi_sf_left = z.maxi_sf_left;
                x.maxi_sf_right = z.maxi_sf_right;
            }
            if (x.maxi_sf == z.sum + y.maxi_sf) {
                if ( x.maxi_sf_left > y.maxi_sf_left ||
                    (x.maxi_sf_left == y.maxi_sf_left
                    && x.maxi_sf_right > z.right)
                 ) {
                    x.maxi_sf_left = y.maxi_sf_left;
                    x.maxi_sf_right = z.right;
                }
            }

            //subarray
            x.maxi_subarray = max( max(y.maxi_subarray, z.maxi_subarray), y.maxi_sf + z.maxi_pf);
            if (x.maxi_subarray == y.maxi_subarray) {
                x.maxi_subarray_left == y.maxi_subarray_left;
                x.maxi_subarray_right = y.maxi_subarray_right;
            }
            if (x.maxi_subarray == z.maxi_subarray) {
                if ( x.maxi_subarray_left > z.maxi_subarray_left ||
                    (x.maxi_subarray_left == z.maxi_subarray_left
                    && x.maxi_subarray_right > z.maxi_subarray_right)
                 ) {
                    x.maxi_subarray_left = z.maxi_subarray_left;
                    x.maxi_subarray_right = z.maxi_subarray_right;
                }
            }
            if (x.maxi_subarray == y.maxi_sf + z.maxi_pf) {
                if ( x.maxi_subarray_left > y.maxi_sf_left ||
                    (x.maxi_subarray_left == y.maxi_sf_left
                    && x.maxi_subarray_right > z.maxi_pf_right) ) {
                    x.maxi_subarray_left = y.maxi_sf_left;
                    x.maxi_subarray_right = z.maxi_pf_right;
                }
            }
        }
        void query(int l, int r, int x) {
            if (data[x].left > r || data[x].right < l) {
                return;
            }
            if (data[x].left >= l && data[x].right <= r) {
                ans1[0] = max(data[x].maxi_subarray, ans2[0] + data[x].maxi_pf);
                if (ans1[0] == data[x].maxi_subarray && ans1[0] != ans2[0] + data[x].maxi_pf) {
                    ans1[1] = data[x].maxi_subarray_left;
                    ans1[2] = data[x].maxi_subarray_right;
                }
                else if (ans1[0] == ans2[0] + data[x].maxi_pf && ans1[0] != data[x].maxi_subarray) {
                    ans1[1] = ans2[1];
                    ans1[2] = data[x].maxi_pf_right;
                }
                else {
                    bool a = data[x].maxi_subarray_left < ans2[1];
                    bool b = data[x].maxi_subarray_left == ans2[1] &&
                            data[x].maxi_subarray_right < data[x].maxi_pf_right;
                    if ( a || b ) {
                        ans1[1] = data[x].maxi_subarray_left;
                        ans1[2] = data[x].maxi_subarray_right;
                    } else {
                        ans1[1] = ans2[1];
                        ans1[2] = data[x].maxi_pf_right;
                    }

                }
                int temp = ans2[0];
                ans2[0] = max(data[x].maxi_sf, temp + data[x].sum);
                if (ans2[0] == data[x].maxi_sf && ans2[0] != temp + data[x].sum ) {
                    ans2[1] = data[x].maxi_sf_left;
                    ans2[2] = data[x].maxi_sf_right;
                }
                else if (ans2[0] == temp + data[x].sum && ans2[0] != data[x].maxi_sf) {
                    ans2[2] = data[x].right;
                }
                else {
                    if ( data[x].maxi_sf_left < ans2[1] ||
                        (data[x].maxi_sf_left == ans2[1] &&
                        data[x].maxi_sf_right < data[x].right)
                    ) {
                        ans2[1] = data[x].maxi_sf_left;
                        ans2[2] = data[x].maxi_sf_right;
                    } else {
                        ans2[2] = data[x].right;
                    }
                }
                if (ans1[0] > ans[0] || ( ans1[0] == ans[0] && ans[1] > ans1[1] || (ans[1] == ans1[1] && ans[2] > ans1[2]) )
                ) {
                    //cout << ans1[0] << " " << ans1[1] << " " << ans1[2] << endl;
                    ans[0] = ans1[0];
                    ans[1] = ans1[1];
                    ans[2] = ans1[2];
                }
                if (ans2[0] > ans[0] || ( ans2[0] == ans[0] && ans[1] > ans2[1] || (ans[1] == ans2[1] && ans[2] > ans2[2]) )
                ) {
                    ans[0] = ans2[0];
                    ans[1] = ans2[1];
                    ans[2] = ans2[2];
                }
                return;
            }
            query(l, r, data[x].lc);
            query(l, r, data[x].rc);
            return;
        }
};

void solve() {

    cout << "Case " << times << ":" << "\n";
    times++;
    ve.clear();
    ve.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    seg_tree seg(ve);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        seg.reset_ans(a);
        seg.query(a, b);
        cout << seg.ans[1] << " " << seg.ans[2] << " " << seg.ans[0] << "\n";
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) solve();

    return 0;
}
