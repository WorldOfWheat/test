#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;

int n, k;
int* arr;

void solve() {
    cin >> n >> k;
    
    arr = new int[n]();
    
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        bitset<30> temp;
        for (int j = 0; j < k; j++) {
            temp[k - j - 1] = s[j] - '0';
        }
        arr[i] = temp.to_ulong();
    }
    
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = arr[i];
            temp ^= arr[j];
            ans = min(ans, __builtin_popcount(temp));
        }
    }
    
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
