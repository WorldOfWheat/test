struct node{
    int left;
    int right;
    int lc;
    int rc;
    int tag;
    int sum;
};

class seg_tree {
    public:
        seg_tree(vector<int> x) {
            _size = x.size();
            input.assign(x.begin(), x.end());
            data.resize(4*_size);
            build(1, _size, 1);
        }
        node query(int l, int r) {
            return query(l, r, 1, _size, 1);
        }
        void update(int l, int r, int value) {
            update(l, r, 1, _size, value, 1);
        }
        void update_single(int pos, int value) {
            update_single(pos, 1, _size, value, 1);
        }
    private:
        int _size;
        vector<int> input;
        vector<node> data;
        int getLc(int x) {
            return x << 1;
        }
        int getRc(int x) {
            return (x << 1) + 1;
        }
        void pull(node &x, node y, node z) {
            x.left = y.left;
            x.right = z.right;
            x.sum = y.sum + z.sum;
        }
        void push(int l, int r, int x) {
            int mid = (l + r) >> 1;
            data[ data[x].lc ].sum += data[x].tag * (mid - l + 1);
            data[ data[x].rc ].sum += data[x].tag * (r - mid);
            data[ data[x].lc ].tag += data[x].tag;
            data[ data[x].rc ].tag += data[x].tag;
            data[x].tag = 0;
        }
        void build(int l, int r, int x) {
            if (l == r) {
                data[x].left = data[x].right = data[x].lc = data[x].rc = l;
                data[x].sum = input[l-1];
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, getLc(x));
            build(mid+1, r, getRc(x));
            data[x].lc = getLc(x);
            data[x].rc = getRc(x);
            pull(data[x], data[ data[x].lc ], data[ data[x].rc ]);
            return;
        }
        node query(int l, int r, int l2, int r2, int x) {
            if (l == l2 && r == r2) {
                return data[x];
            }
            push(l2, r2, x);
            int mid = (l2 + r2) >> 1;
            if (r <= mid) {
                return query(l, r, l2, mid, getLc(x));
            }
            else if (l > mid) {
                return query(l, r, mid+1, r2, getRc(x));
            }
            else {
                node a = query(l, mid, l2, mid, getLc(x));
                node b = query(mid+1, r, mid+1, r2, getRc(x));
                node result;
                pull(result, a, b);
                return result;
            }
        }
        void update(int l, int r, int l2, int r2, int value, int x) {
            if (l == l2 && r == r2) {
                data[x].sum += (r - l + 1) * value;
                data[x].tag += value;
                return;
            }
            push(l2, r2, x);
            int mid = (l2 + r2) >> 1;
            if (r <= mid) {
                update(l, r, l2, mid, value, getLc(x));
            }
            else if (l > mid) {
                update(l, r, mid+1, r2, value, getRc(x));
            }
            else {
                update(l, mid, l2, mid, value, getLc(x));
                update(mid+1, r, mid+1, r2, value, getRc(x));
            }
            pull(data[x], data[ data[x].lc ], data[ data[x].rc ]);
            return;
        }
        void update_single(int pos, int l2, int r2, int value, int x) {
            if (pos == l2 && pos == r2) {
                data[x]._xor = value;
                return;
            }
            int mid = (l2 + r2) >> 1;
            if (pos <= mid) {
                update_single(pos, l2, mid, value, data[x].lc);
            }
            else {
                update_single(pos, mid+1, r2, value, data[x].rc);
            }
            pull(data[x], data[ data[x].lc ], data[ data[x].rc ]);
        }
};
