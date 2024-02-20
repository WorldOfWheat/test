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
        stack<int> ans_stack;
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
                int last = num_stack.top();
                int sum = 0;
                num_stack.pop();
                while (num_stack.top() != 0) {
                    int num1 = num_stack.top();
                    num_stack.pop();
                    sum += abs(last - num1);
                    last = num1;
                }
                num_stack.pop();
                int top_ans = 0;
                if (ans_stack.size()) {
                    top_ans = ans_stack.top();
                }
                ans_stack.push((sum * magnification_stack.top()) + abs(tail - last) * (magnification_stack.top() - 1) + top_ans * magnification_stack.top());
                magnification_stack.pop();
            }
        }
        
        while (ans_stack.size()) {
            cerr << ans_stack.top() << '\n';   
            ans_stack.pop();
        }
        // int last = num_stack.top();
        // num_stack.pop();
        // while (num_stack.size()) {
        //     ans += abs(last - num_stack.top());            
        //     last = num_stack.top();
        //     num_stack.pop();
        // }
        // 
        // cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
