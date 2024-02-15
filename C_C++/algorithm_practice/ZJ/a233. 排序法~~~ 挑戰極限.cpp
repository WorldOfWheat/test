#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

void quick_sort(vi* arr, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    
    int pivot = (*arr)[left];
    int l = left, r = right - 1;
    while (l < r) {
        while (r > l && (*arr)[r] >= pivot) {
            r--;
        }
        while (l < r && (*arr)[l] <= pivot) {
            l++;
        }            
        if (l < r) {
            swap((*arr)[l], (*arr)[r]);
        }
    }
    swap((*arr)[left], (*arr)[l]);

    quick_sort(arr, left, l);
    quick_sort(arr, l+1, right);
}

void solve() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    mt19937 rng(time(0));
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        // swap(arr[i], arr[rng() % size]);
    }

    quick_sort(&arr, 0, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
