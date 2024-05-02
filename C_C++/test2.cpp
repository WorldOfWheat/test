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

mt19937 rand_gen(time(0));
int n, m;
vi arr;

void quick_sort(vi& arr, int l, int r) {
    if (l + 1 >= r) {
        return;
    }

    int pivot = l;
    int l_ptr = l;
    int r_ptr = r - 1;
    while (l_ptr < r_ptr) {
        while (l_ptr < r_ptr && arr[r_ptr] >= arr[pivot]) {
            r_ptr--;
        }
        while (l_ptr < r_ptr && arr[l_ptr] <= arr[pivot]) {
            l_ptr++;
        }
        if (l_ptr < r_ptr) {
            swap(arr[l_ptr], arr[r_ptr]);
        }
    }
    swap(arr[l_ptr], arr[l]);
    
    quick_sort(arr, l, l_ptr);
    quick_sort(arr, l_ptr + 1, r);
}

void solve() {
    cin >> n;
    
    arr.resize(n);
    for (int& i : arr) {
        cin >> i;
    }
    
    shuffle(arr.begin(), arr.end(), rand_gen);
    quick_sort(arr, 0, n);
    
    for (int i : arr) {
        cout << i << ' ';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
