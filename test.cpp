#include <bits/stdc++.h>
//#define int long long
#define pa pair<int, int>
#define tp tuple<int, int, int>
#define db(x) cout << x << " "

using namespace std;
__attribute__((optimize("-O3")))

int n;
int arr[(int)1e7+1];
int temp_arr[(int)1e7+1];
int arr2[(int)1e7+1];
int ps[(int)1e7+2];
int maxi;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr2[i];
    }
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i-1] + arr[i]*arr2[i];
    }
    maxi = ps[n];
    for (int i = 2; i <= n; i++) {
        copy(arr, arr+n+1, temp_arr);
        for (int j = 1; j <= i-1 && i+j <= n; j++) {
            int sum = 0;
            swap(temp_arr[abs(i-j)], temp_arr[i+j]);
            sum += ps[i-j-1]-ps[0];
            sum += ps[n]-ps[i+j];
            int l = abs(i-j);
            int r = i+j;
            while (l < r) {
                sum += temp_arr[l]*arr2[l];
                sum += temp_arr[r]*arr2[r];
                l++;
                r--;
            }
            sum += temp_arr[l]*arr2[l];
            maxi = max(maxi, sum);
        }
        copy(arr, arr+n+1, temp_arr);
        for (int j = 1; j <= i-1 && i+j-1 <= n; j++) {
            int sum = 0;
            swap(temp_arr[abs(i-j)], temp_arr[i+j-1]);
            sum += ps[i-j-1]-ps[0];
            sum += ps[n]-ps[i+j-1];
            int l = abs(i-j);
            int r = i+j-1;
            while (l < r) {
                sum += temp_arr[l]*arr2[l];
                sum += temp_arr[r]*arr2[r];
                l++;
                r--;
            }
            maxi = max(maxi, sum);
        }
    }
    cout << maxi << endl;

    return 0;
}
