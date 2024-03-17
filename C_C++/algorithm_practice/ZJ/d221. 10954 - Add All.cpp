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
vi arr;

void solve() {
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        arr.resize(n); 
        for (int& i : arr) {
            cin >> i;
        }
        
        priority_queue<int, vi, greater<int>> pq;
        for (int& i : arr) {
            pq.push(i);
        }
        
        int ans = 0;
        while (pq.size() > 1) {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            int sum = num1 + num2;
            pq.push(sum);
            ans += sum;
        }
        
        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
