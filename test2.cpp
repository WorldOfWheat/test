#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 20;
int a[maxn];
long long dp[maxn][10][2]; //dp[pos][now][lim]
long long ans;
 
long long solve(int pos, int now, int lim) {
    //lim = 0 (無限制，可填now～9），lim = 1（有限制，受限於其上一位數）
    if (dp[pos][now][lim] != -1) return dp[pos][now][lim];
    if (pos == 0) return dp[pos][now][lim] = 1; //個位數
    long long ret = 0;
    if (lim) {
        //lim = 1（有限制，受限於其上一位數）
        for (int i = now; i < a[pos-1]; i++) {
            ret += solve(pos-1, i, 0);
        }
        if (a[pos-1] >= now) {
            ret += solve(pos-1, a[pos-1], 1);
        }
    } else {
        //lim = 0 (無限制，可填now～9）
        for (int i = now; i < 10; i++){
            ret += solve(pos-1, i, 0);
        }
    }
    return dp[pos][now][lim] = ret;
}
 
int main() {
    long long N;
    cin >> N;
    int mx = 0; //最高位數，10^mx
    for (int i = 0; i < maxn; i++) {
        a[i] = N % 10;
        N /= 10;
        if (N == 0) {
            mx = i;
            break;
        }
    }
    memset(dp, -1, sizeof(dp));
    //從最高位數開始填表
    /*for (int i = 0; i < a[mx]; i++) {
        ans += solve(mx, i, 0);
    }*/
    ans += solve(mx, a[mx], 1);
    cout << ans << "\n";
    return 0;
}