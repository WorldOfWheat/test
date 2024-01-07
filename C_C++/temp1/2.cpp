#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

const vector<pii> move_dir = {
    {0, -2},
    {-1, -1},
    {-1, 1},
    {0, 2},
    {1, -1},
    {1, 1},
};
const vector<string> table = {
    {"Q W E R T Y U I O P"},
    {" A S D F G H J K L"},
    {"  Z X C V B N M"},
}; 

int t;
char ch;

void solve()
{
    cin >> t >> ch;

    int current_x = 0, current_y = 0;
    bool stop = false;
    for (int i = 0; i < 3 && !stop; i++) 
    {
        for (int j = 0; j < table[i].size(); j++)
        {
            if (table[i][j] == ch) 
            {
                current_x = i;
                current_y = j;
                stop = true;
                break;
            }
        }
    }
    
    while (t--)
    {
        int a, b;
        cin >> a;
        if (a == 1) 
        {
            cin >> b;
            b--;
            int next_dir_x = current_x + move_dir[b].first;
            int next_dir_y = current_y + move_dir[b].second;
            // cerr << '#' << next_dir_x << ' ' << next_dir_y << '\n';
            if (next_dir_x >= 3 || next_dir_x < 0) continue;
            if (next_dir_y >= table[next_dir_x].size() || next_dir_y < 0) continue;
            if (table[next_dir_x][next_dir_y] == ' ') continue;
            // cerr << "##" << next_dir_x << ' ' << next_dir_y << ' ' << table[next_dir_x][next_dir_y] << '\n';
            current_x = next_dir_x;
            current_y = next_dir_y;
        }
        if (a == 2) 
        {
            cout << table[current_x][current_y];
        }
    }
}

int main()
{
    fastio;
    solve();
    return 0;
}
