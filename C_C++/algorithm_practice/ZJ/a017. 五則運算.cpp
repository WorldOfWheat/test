#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;

map<char, int> op_priority = {
    {')', 6},
    {'+', 4},
    {'-', 4},
    {'*', 5},
    {'/', 5},
    {'%', 5},
    {'(', 3},
};

auto calcualte = [] (int a, int b, char c) {
    switch (c) {
        case '+': {
            return a + b;
        }
        case '-': {
            return a - b;
        }
        case '*': {
            return a * b;
        }
        case '/': {
            return a / b;
        }
        case '%': {
            return a % b;
        }
    };
};

void solve() {
    string s;
    while (getline(cin, s)) {
        stack<int> num;
        stack<char> symbol;
        string num_temp;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num_temp.push_back(s[i]);
                continue;
            }                
            if (num_temp.size()) {
                num.push(stol(num_temp));
                num_temp.clear();
            }
            if (s[i] == ' ') {
                continue;
            }
            if (symbol.empty() || s[i] == '(') {
                symbol.push(s[i]);
                continue;
            }
            if (s[i] == ')') {
                while (symbol.top() != '(') {
                    char op1 = symbol.top();
                    symbol.pop();
                    int num2 = num.top();
                    num.pop();
                    int num1 = num.top();
                    num.pop();
                    num.push(calcualte(num1, num2, op1));
                }
                symbol.pop();
                continue;
            }
            while (symbol.size() && op_priority[s[i]] <= op_priority[symbol.top()]) {
                char op1 = symbol.top();
                symbol.pop();
                int num2 = num.top();
                num.pop();
                int num1 = num.top();
                num.pop();
                num.push(calcualte(num1, num2, op1));
            }
            symbol.push(s[i]);
        }
        if (num_temp.size()) {
            num.push(stol(num_temp));
            num_temp.clear();
        }

        // while (num.size()) {
        //     cerr << num.top() << ' ';
        //     num.pop();
        // }
        // cerr << '\n';
        // while (symbol.size()) {
        //     cerr << symbol.top() << ' ';
        //     symbol.pop();
        // }
        // cerr << '\n';

        // cerr << num.size() << ' ' << symbol.size() << '\n';

        while (num.size() > 1) {
            char op1 = symbol.top();
            symbol.pop();
            int num2 = num.top();
            num.pop();
            int num1 = num.top();
            num.pop();
            num.push(calcualte(num1, num2, op1));
        }
        
        cout << num.top() << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
