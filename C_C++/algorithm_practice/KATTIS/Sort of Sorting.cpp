#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<bool> vb;
typedef vector<vb> v2b;

int n;    
vs arr;

bool compare(string& a, string& b) {
    return a.substr(0,2) <= b.substr(0,2);    
}

void merge_sort(vs& arr, int l, int r) {
    if (l + 1 >= r) {
        return;
    }

    int mid = (l + r) >> 1;
    
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    
    vs temp(r - l);
    int temp_index = 0;
    int l_ptr = l;
    int r_ptr = mid;
    while (l_ptr < mid && r_ptr < r) {
        if (compare(arr[l_ptr], arr[r_ptr])) {
            temp[temp_index++] = arr[l_ptr++];
        }
        else {
            temp[temp_index++] = arr[r_ptr++];
        }
    }
    while (l_ptr < mid) {
        temp[temp_index++] = arr[l_ptr++];
    }
    while (r_ptr < r) {
        temp[temp_index++] = arr[r_ptr++];
    }
    for (int i = l; i < r; i++) {
        arr[i] = temp[i - l];
    }
}

void solve() {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        merge_sort(arr, 0, n);
        
        for (string i : arr) {
            cout << i << '\n';
        }
        cout << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
