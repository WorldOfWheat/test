class BIT_tree {
    public:
        BIT_tree(int x) {
            _size = x + 1;
            data.resize(_size);
        }
        void update(int pos, int value) {
            for (int i = pos; i <= _size; i+=getLowbit(i)) {
                data[i] += value;
            }
        }
        int query(int pos) {
            int res = 0;
            for (int i = pos; i >= 1; i-=getLowbit(i)) {
                res += data[i];
            }
            return res;
        }
    private:
        int _size;
        vector<int> data;
        int getLowbit(int x) {
            return (x & -x);
        }
};
