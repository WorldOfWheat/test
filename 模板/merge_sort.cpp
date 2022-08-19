void merge_sort(vector<int> &x, int l, int r) {

    if (l == r) {
        return;
    }

    int mid = (l + r) >> 1;
    merge_sort(x, l, mid);
    merge_sort(x, mid+1, r);

    vector<int> res;
    int l2 = l;
    int r2 = mid+1;
    while (l2 <= mid && r2 <= r) {
        if (x[l2] < x[r2]) {
            res.push_back(x[l2]);
            l2++;
        }
        else {
            res.push_back(x[r2]);
            r2++;
        }
    }

    while (l2 <= mid) {
        res.push_back(x[l2]);
        l2++;
    }

    while (r2 <= r) {
        res.push_back(x[r2]);
        r2++;
    }
    for (int i = 0; i < res.size(); i++) {
        x[i+l] = res[i];
    }
}
