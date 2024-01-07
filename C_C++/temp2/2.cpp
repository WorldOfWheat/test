#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;

int n, m;
vector<string> arr;
string str;

void solve()
{
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cin >> m;
    cin >> str;
    
    stringstream ss;
    int cursor_x = 0; 
    int cursor_y = n-1;
    int ptr = 0;
    bool flag = false;

    while (ptr < m)
    {
        string temp;
        int scan_cursor_x = cursor_x;
        int scan_cursor_y = cursor_y;
        while (scan_cursor_x < n && scan_cursor_y < n) 
        {
            temp.push_back(arr[scan_cursor_x][scan_cursor_y]);
            scan_cursor_x++;
            scan_cursor_y++;
        }
        if (str[ptr++] == '1') reverse(temp.begin(), temp.end());
        ss << temp;
        // cerr << temp << ' ' << flag << '\n';
        
        if (!flag) cursor_y--;
        else cursor_x++;
        if (!flag && cursor_y < 0) 
        {
            cursor_y = 0;
            cursor_x = 1;
            flag = true;
        }
    }
    
    cout << ss.str() << '\n';
}

signed main()
{
    fastio;
    solve();
    return 0;
}
