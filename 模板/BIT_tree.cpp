class bit{
    public:
        bit(int x) {
            data.resize(x+1);
            _size = x;
        }
        void update(int x, int y) {
            for (int i = x; i <= _size; i+=lowbit(i)) {
                data[i] += y;
            }
        }
        int query(int x) {
            int result = 0;
            for (int i = x; i >= 1; i-=lowbit(i)) {
                result += data[i];
            }
            return result;
        }
        void test(int x) {
            cout << (lowbit(x)) << endl;
        }

    private:
        vector<int> data;
        int _size;
        int lowbit(int x) {
            return (x & -x);
        }
};
