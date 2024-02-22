#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<string> vs;
typedef vector<vs> v2s;
typedef vector<pii> vp;
typedef vector<vp> v2p;

void solve() {
    string s;
    while (cin >> s) {
        vi nums;
        vi magnifications;
        vi sums;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'T') {
                int num = (s[i+1] - '0') * 10 + (s[i+2] - '0');
                nums.push_back(num);
                i += 2;
                continue;
            }
            if (s[i] == 'L') {
                int magnification = s[i+1] - '0'; 
                magnifications.push_back(magnification);
                nums.push_back(-1);
                i += 1;
                continue;
            }
            if (s[i] == 'E') {
                for (auto i : nums) {
                    cerr << i << ' ';
                }
                cerr << '\n';
                int tail = nums.back();
                int head = nums.back();
                nums.pop_back();
                int sum = 0;
                while (nums.back() != -1) {
                    sum += abs(head - nums.back());                                        
                    head = nums.back();
                    nums.pop_back();
                }
                nums.pop_back();
                nums.push_back(head);
                nums.push_back(tail);
                int sums_top = 0;
                if (sums.size()) {
                    sums_top = sums.back();
                    sums.pop_back();
                }
                sums.push_back(sums_top * magnifications.back() + sum * magnifications.back() + abs(tail - head) * (magnifications.back() - 2));
                magnifications.pop_back();
                // for (auto i : nums) {
                //     cerr << i << ' ';
                // }
                // cerr << '\n';
            }
        }
        int head = nums.back();
        nums.pop_back();
        int sum = 0;
        while (nums.size()) {
            sum += abs(head - nums.back());                                        
            head = nums.back();
            nums.pop_back();
        }
        if (sums.size()) {
            sum += sums.back();
        }
        cout << sum << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
