#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "

using namespace std;

void solve() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sum = a + b + c + d;
    cin >> a >> b >> c >> d;
    int sum2 = a + b + c + d;
    cout << sum << ":" << sum2 << ln;

    cin >> a >> b >> c >> d;
    int sum3 = a + b + c + d;
    cin >> a >> b >> c >> d;
    int sum4 = a + b + c + d;
    cout << sum3 << ":" << sum4 << ln;

    if (sum > sum2 && sum3 > sum4) {
        cout << "Win" << ln;
    }
    else if (sum < sum2 && sum3 < sum4) {
        cout << "Lose" << ln;
    }
    else {
        cout << "Tie" << ln;
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
