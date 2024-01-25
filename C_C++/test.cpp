#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<v2p> v3p;
typedef vector<string> vs;

string s;

vi add(vi* a, vi* b) {
    int l = 0, r = 0;
    int carry = 0;
    vi result;
    while (l < a->size() && r < b->size()) {
        int sum = ((*a)[l] + (*b)[r] + carry) % 10;
        result.push_back(sum);
        carry = ((*a)[l] + (*b)[r] + carry) / 10;
        l++, r++;
    }
    while (l < a->size()) {
        int sum = ((*a)[l] + carry) % 10;
        result.push_back(sum);
        carry = ((*a)[l] + carry) / 10;
        l++;
    }
    while (r < b->size()) {
        int sum = ((*b)[r] + carry) % 10;
        result.push_back(sum);
        carry = ((*b)[r] + carry) / 10;
        r++;
    }
    return result;
}

vi minius(vi* a, vi* b) {
    int l = 0, r = 0;
    int carry = 0;
    vi result;
    while (l < a->size() && r < b->size()) {
        if ((*a)[l] - carry < (*b)[r]) {
            result.push_back(10 + (*a)[l] - (*b)[r] - carry);
            carry = 1;
            l++, r++;
            continue;
        }
        result.push_back((*a)[l] - carry - (*b)[r]);
        carry = 0;
        l++, r++;
    }
    while (l < a->size()) {
        result.push_back((*a)[l] - carry);
        carry = 0;
        l++;
    }
    while (r < b->size()) {
        result.push_back((*a)[l] - carry);
        carry = 0;
        r++;
    }
    while (result.back() == 0) {
        result.pop_back();
    }
    return result;
}

inline int calculate(int a, int b, char c) {
    switch (c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

inline int get_priority(char _operator)
{
    switch (_operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return -1;
    }
}

void solve() {
    vi a = {0, 0, 2};
    vi b = {2, 7, 1};
    vi result = minius(&a, &b);
    for (int i = 0; i < result.size(); i++) {
        cerr << result[i] << ' ';
    }

    return;
    cin >> s;
    
    vi numbers;
    vector<char> operators;
    string number_buffer = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            number_buffer += s[i];
            continue;
        }        
        if (!number_buffer.empty()) {
            numbers.push_back(stoi(number_buffer));
            number_buffer = "";
        }

        if (operators.empty() || s[i] == '(') {
            operators.push_back(s[i]);
            continue;
        }
        
        if (s[i] == ')') {
            while (operators.back() != '(') {
                int a = numbers.back();
                numbers.pop_back();
                int b = numbers.back();
                numbers.pop_back();
                char c = operators.back();
                operators.pop_back();
                numbers.push_back(calculate(b, a, c));
            }
            operators.pop_back();
            continue;
        }

        if (get_priority(operators.back()) > get_priority(s[i])) {
            int a = numbers.back();
            numbers.pop_back();
            int b = numbers.back();
            numbers.pop_back();
            char c = operators.back();
            operators.pop_back();
            numbers.push_back(calculate(b, a, c));
            operators.push_back(s[i]);
            continue;
        }
        
        operators.push_back(s[i]);
    }
    if (!number_buffer.empty()) {
        numbers.push_back(stoi(number_buffer));
    }
    
    int j = 0;
    for (int i = 1; i < numbers.size(); i += 1) {
        int a = numbers[i - 1];
        int b = numbers[i];
        char c = operators[j];
        numbers[i] = calculate(a, b, c);
        j++;
    }
    cout << numbers.back() << '\n';
    
}

signed main() {
    fastio;
    solve();
    return 0;
}
