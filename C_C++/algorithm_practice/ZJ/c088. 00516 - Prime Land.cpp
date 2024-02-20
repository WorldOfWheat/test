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

int pow(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result *= base;        
        }
        base *= base;
        exponent >>= 1;
    }
    return result;
}

bool is_prime(int num) {
    for (int i = 2; i <= (int) __builtin_sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

vi build_prime_table() {
    vi result;
    for (int i = 2; i <= 2e5; i++) {
        if (is_prime(i)) {
            result.push_back(i);
        }
    }
    return result;
}

vp prime_factor(vi& prime_table, int num) {
    vp result;
    for (int i = 0; i < prime_table.size(); i++) {
        if (num % prime_table[i] == 0) {
            int base = prime_table[i];
            int exponent = 0;
            while (num % prime_table[i] == 0) {
                num /= prime_table[i];
                exponent++;
            }
            result.push_back({base, exponent});
        }
    }

    return result;
}

vi read() {
    string s;
    getline(cin, s);
    
    vi result;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            result.push_back(stoi(temp));            
            temp = "";
            continue;
        }
        temp += s[i];
    }
    result.push_back(stoi(temp));            
    
    return result;
}

void solve() {
    vi prime_table = build_prime_table();

    while (true) {
        vi arr = read();
        if (arr[0] == 0) {
            break;
        }

        int num = 1;
        for (int i = 0; i < arr.size(); i++) {
            int base = arr[i++];
            int exponent = arr[i];
            num *= pow(base, exponent);
        }
        num--;
        
        vp factors = prime_factor(prime_table, num);
        reverse(factors.begin(), factors.end());
        for (int i = 0; i < factors.size(); i++) {
            cout << factors[i].first << ' ' << factors[i].second << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
