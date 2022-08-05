class DSU {
    public:
        DSU(int x) {
            _size = x;
            cnt = _size;
            data.resize(_size + 1);
            for (int i = 0; i <= _size; i++) {
                data[i] = i;
            }
        }
        void connect(int x, int y) {
            int a = query(data[x]);
            int b = query(data[y]);
            data[a] = b;
        }
        bool isConnected(int x, int y) {
            return ( query(x) == query(y) );
        }
    private:
        int _size;
        int cnt;
        vector<int> data;
        int query(int x) {
            if (data[x] == x) {
                return x;
            }
            return query(data[x]);
        }
};
