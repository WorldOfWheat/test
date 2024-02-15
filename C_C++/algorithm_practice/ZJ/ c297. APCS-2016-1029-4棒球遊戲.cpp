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
    v2s arr(9);
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        while (a--) {
            string b;
            cin >> b;
            arr[i].push_back(b);
        }
    }
    vs commands;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[j].size() <= i) {
                continue;
            }
            commands.push_back(arr[j][i]);
        }
    }
    
    int n;
    cin >> n;
    int out_counter = 0;
    int index = 0;
    int bases = 0;
    int score = 0;
    while (out_counter < n) {
        string command = commands[index++];
        if (command[1] == 'O') {
            out_counter++;
            if (out_counter % 3 == 0) {
                bases = 0;
            }
            continue;
        }
        if (command[1] == 'B' || command == "HR") {
            if (command[0] == '1') {
                bases <<= 1;
                bases |= 1;
            }
            if (command[0] == '2') {
                bases <<= 2;
                bases |= 1 << 1;
            }
            if (command[0] == '3') {
                bases <<= 3;
                bases |= 1 << 2;
            }
            if (command == "HR") {
                bases <<= 4;
                score++;
            }
            score += __builtin_popcount(bases >> 3);
            bases &= (1 << 3) - 1;
        }
    }
    
    cout << score << '\n';
}

signed main() {
    fastio;
    solve();
    return 0;
}
