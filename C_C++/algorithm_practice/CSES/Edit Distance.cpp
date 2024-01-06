#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

string str1;
string str2;
vector<vi> dp;

void solve() 
{
    cin >> str1 >> str2;
    int size1 = str1.size();
    int size2 = str2.size();
    
    dp.resize(size1 + 1, vi(size2 + 1));
    for (int i = 0; i <= size1; i++) dp[i][0] = i;
    for (int i = 0; i <= size2; i++) dp[0][i] = i;
    
    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            if (str1[i-1] == str2[j-1]) 
            {
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }
    
    cout << dp[size1][size2] << '\n';
}

int main() 
{
    fastio;
    solve();
    return 0;
}
