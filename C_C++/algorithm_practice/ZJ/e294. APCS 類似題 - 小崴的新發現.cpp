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

void solve() {
    string s;
    while (cin >> s) {
        int first_even_index = 0;
        while (first_even_index < s.size() && (s[first_even_index] - '0') % 2 != 0) {
            first_even_index++;
        }
        if (first_even_index == s.size()) {
            cout << "0\n";
            continue;
        }
        if (s.size() == 1 && first_even_index == 0) {
            cout << "1\n";
            continue;
        }
        
        string s2 = s;
        s2[first_even_index]++;
        for (int i = first_even_index + 1; i < s2.size(); i++) {
            s2[i] = '1';
        }

        string s3 = s;
        int carry_index = first_even_index;
        int carry = 0;
        if (s3[first_even_index] == '0') {
            s3[first_even_index] = '9';
            carry = 1;
        }
        else {
            s3[first_even_index]--;
        }

        carry_index--;
        while (carry_index > 0 && carry != 0) {
            s3[carry_index] -= 2;
            if (s3[carry_index] < '0') {
                s3[carry_index] = '9';
                carry = 1;
            }
            carry_index--;
        }
        
        if (carry_index == 0 && carry) {
            s3[carry_index] -= 2;
            if (s3[carry_index] < '0') {
                s3.erase(s3.begin());
                first_even_index--;
            }
        }

        for (int i = first_even_index + 1; i < s3.size(); i++) {
            s3[i] = '9';
        }
        
        int ans = min(abs(stol(s) - stol(s2)), abs(stol(s) - stol(s3)));
        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
