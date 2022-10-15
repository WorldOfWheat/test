#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;
const int maxK = 105;
const long long INF = 1e18;
long long dp[2][2][maxK];
int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    
    int old = 0;
    int young = 1;
    for(int i = 0; i < maxK; i++) dp[0][1][i] = -INF;
    for(int i = 0; i < N; i++){
        int p;
        cin >> p;
        
        for(int j = 0; j < K; j++) 
            dp[young][1][j] = max(dp[old][0][j] - p, dp[old][1][j]);
            
        for(int j = 1; j <= K; j++) 
            dp[young][0][j] = max(dp[old][1][j-1] + p, dp[old][0][j]);
        
        old = 1 - old;
        young = 1 - young;
    }
    
    long long ans = -INF;
    for(int i = 0; i <= K; i++) ans = max(ans, dp[old][0][i]);
    cout << ans;
    return 0;
}