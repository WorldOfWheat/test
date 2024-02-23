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

int f(string& s, int& index, int& head, int& tail) {
    if (index >= s.size()) {
        head = -1;
        tail = -1;
        return 0;
    }

    int result = 0;
    while (index < s.size()) {
        if (s[index] == 'T') {
            int len = (s[index + 1] - '0') * 10 + (s[index + 2] - '0');
            index += 3;
            int next = f(s, index, head, tail);
            if (head == -1) {
                result = next;
            }
            else {
                result += abs(len - head) + next;
            }
            head = len;
            if (tail == -1) {
                tail = len;
            }
            continue;
        }
        if (s[index] == 'L') {
            int magnification = (s[index + 1] - '0');
            index += 2;
            int next = f(s, index, head, tail);
            int tail2 = tail;
            result = next * magnification + (magnification - 1) * abs(tail - head);
            result += abs(tail2 - tail);
            continue;
        }
        if (s[index] == 'E') {
            tail = -1;
            return 0;
        }
    }

    return result;
}

void solve() {
    string s;
    while (cin >> s) {
        int index = 0;
        int head = 0;
        int tail = 0;
        cout << f(s, index, head, tail) << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
