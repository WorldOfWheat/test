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
        stack<int> num_stack;
        stack<int> magnification_stack;
        stack<char> symbol_stack;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'T') {
                int num_temp = 0;
                i++;
                num_temp += s[i] - '0';
                num_temp *= 10;
                i++;
                num_temp += s[i] - '0';
                num_stack.push(num_temp);
                continue;
            }
            if (s[i] == 'L') {
                i++;
                int magnification = s[i] - '0';
                magnification_stack.push(magnification);
                num_stack.push(0);
                continue;
            }
            if (s[i] == 'E') {
                int tail = num_stack.top();
                int head;
                int sum = 0;
                int last = num_stack.top();
                num_stack.pop();
                while (num_stack.top() != 0) {
                    int num1 = num_stack.top();
                    num_stack.pop();
                    head = num1;
                    sum += abs(last - num1);
                    last = num1;
                }
                cerr << sum << '\n';
            }
        }
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
