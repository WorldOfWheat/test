#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[(int) 2e6 + 5];
int pf[(int) 2e6 + 5];

signed main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        pf[i] = pf[i-1] + arr[i-1];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        cout << (pf[b] - pf[a - 1]) << '\n';
    }

    return 0;

}
