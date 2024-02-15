#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

void solve() {
    int t = 1;
    int n, m;
    while (cin >> n >> m) {
        cout << "Selection #" << t << "\n" ;
        t++;

        vi arr(20);
        for (int i = 0; i < 20; i++) {
            cin >> arr[i];
        }

        vector<bool> deaths(n);
        int count = n;
        int card_index = 0;
        while (card_index < 20 && count > m) {
            int index = 0;
            while (count > m && index < n) {
                int count2 = 0;
                while (index < n && count2 < arr[card_index] - 1) {
                    if (!deaths[index]) {
                        count2++;
                    }
                    index++;
                }
                while (index < n && deaths[index]) index++;
                
                if (index < n) {
                    deaths[index] = true;
                    index++;
                    count--;
                }
            }
            card_index++;
        }
        
        for (int i = 0; i < n; i++) {
            if (!deaths[i]) {
                cout << i + 1 << ' ';
            }
        }
        cout << "\n\n";
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
