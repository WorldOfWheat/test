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

int f(string& s, int& index, int& head, int& tail, int& tail_index) {
    if (index >= s.size()) {
        tail_index = index;
        return 0;
    }

    if (s[index] == 'T') {
        int len = (s[index + 1] - '0') * 10 + (s[index + 2] - '0');
        index += 3;
        int result = f(s, index, head, tail, tail_index);
        // cerr << "# " << head << ' ' << tail << ' ' << len << ' ' << result << '\n';
        if (tail == -1) {
            tail = len;
        }
        if (head != -1) {
            result += abs(head - len);
        }
        head = len;
        // cerr << "## " << head << ' ' << tail << ' ' << len << ' ' << result << '\n';
        return result;
    }
    if (s[index] == 'L') {
        int magnification = s[index + 1] - '0';
        index += 2;
        int sum = f(s, index, head, tail, tail_index);
        // cerr << "* " << sum << ' ' << head << ' ' << tail << '\n';
        int result = sum * magnification + abs(head - tail) * (magnification - 1);
        // cerr << "** " << result << '\n';
        index = tail_index + 1;
        tail_index = -1;
        int tail2 = -1;
        int head2 = -1;
        result += f(s, index, head2, tail2, tail_index);
        if (head2 != -1) {
            result += abs(tail - head2);
        }
        // cerr << "*** " << tail << ' ' << head2 << ' ' << tail2 << '\n';
        if (tail2 != -1) {
            tail = tail2;
        }
        // result += abs(tail2 - head);
        return result;
    }
    if (s[index] == 'E') {
        tail_index = index;
        return 0;
    }
}

void solve() {
    string s;
    while (cin >> s) {
        int index = 0;
        int head = -1;
        int tail = -1;
        int tail_index = 0;
        cout << f(s, index, head, tail, tail_index) << '\n';
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}
