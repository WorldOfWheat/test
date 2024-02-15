#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

pii f(string& str, int index) {
    // cerr << str.substr(index) << ' ' << index << '\n';
    stack<int> nums;    
    stack<char> ops;    
    int i;
    for (i = index; i < str.size(); i++) {
        if (isdigit(str[i])) {
            int num = 0;
            while (i < str.size() && isdigit(str[i])) {
                num *= 10;
                num += str[i] - '0';
                i++;
            }
            nums.push(num);
        }
        if (str[i] == 'f') {
            int right_bracket_index = i + 2;
            int bracket_counter = 1;
            while (right_bracket_index < str.length() && bracket_counter != 0) {
                if (str[right_bracket_index] == '(') bracket_counter++;
                if (str[right_bracket_index] == ')') bracket_counter--;
                right_bracket_index++;
            }

            i += 2;
            int maximum = -1e18;
            int minimum = 1e18;
            while (i < right_bracket_index) {
                pii part = f(str, i);                
                maximum = max(maximum, part.first);
                minimum = min(minimum, part.first);
                i = part.second + 1;
            }
            nums.push(maximum - minimum);
        }
        if (str[i] == '*') {
            while (ops.size() && ops.top() == '+') {
                ops.pop();
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num1 + num2);
            }
            ops.push(str[i]);
        }
        if (str[i] == '+') {
            ops.push('+');
        }
        if (str[i] == ',' || str[i] == ')') {
            break;
        }
    }
    
    while (nums.size() > 1) {
        char op = ops.top();
        ops.pop();
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        if (op == '*') {
            nums.push(num1 * num2);
        } else {
            nums.push(num1 + num2);
        }
    }
    
    return {nums.top(), i};
}

void solve() {
    string s;
    cin >> s;
    cout << f(s, 0).first << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
