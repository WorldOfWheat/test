class DSU {
    public:
        DSU(int x) {
            _size = x;
            data.resize(_size + 1);
            for (int i = 0; i <= _size; i++) {
                data[i] = i;
            }
        }
        void update(int pos, int pos2) {
            data[query(pos)] = query(pos2);
        }
        int query(int pos) {
            if (data[pos] == pos) {
                return pos;
            }
            return data[pos] = query(data[pos]);
        }
    private:
        int _size;
        vector<int> data;
};
