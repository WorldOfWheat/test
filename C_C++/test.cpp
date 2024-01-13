#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0);
// #define int long long

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef vector<pii> vp;
typedef vector<vp> v2p;
typedef vector<v2p> v3p;
typedef vector<string> vs;

int n;
string s;

void solve()
{
    cin >> n;
    
    int status = 0;
    bool lock_mode = false;
    string vault_password = "mypassword";
    string admin_password = "admin";
    string current_status = "000000";
    int wrong_password_count = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> s;
        
        if (s == "OFF") status = 0;
        if (status != 0)
        {
            if ((s == "!X0" || s == "X4" || s == "X5")) 
            {
                status = -1;
                current_status = "110000";
                cout << current_status << '\n';
            }
            if (s == "X3") 
            {
                lock_mode = true;
                cout << current_status << '\n';
            }
            if (s == "!X3") 
            {
                lock_mode = false;
                cout << current_status << '\n';
            }
        }

        switch (status)
        {
            case 0:
            {
                lock_mode = false;
                vault_password = "mypassword";
                admin_password = "admin";
                wrong_password_count = 0;

                if (s == "ON") 
                {
                    status = 1;
                    current_status = "010000";
                    cout << current_status << '\n';
                }
                else
                {
                    current_status = "000000";
                    cout << current_status << '\n';
                }
                break;
            }
            case 1:
            {
                if (s == "X1")
                {
                    status = 2;
                    current_status = "011000";
                    cout << current_status << '\n';
                }
                else
                {
                    current_status = "010000";
                    cout << current_status << '\n';
                }
                break;
            }
            case 2:
            {
                if (s[0] != '\"') 
                {
                    current_status = "011000";
                    cout << current_status << '\n';
                    break;
                }
                cin >> s;
                if (s == vault_password) 
                {
                    if (lock_mode = false)
                    {
                        status = 3;
                        current_status = "011100";
                        cout << current_status << '\n';
                    }
                    break;
                }
                if (s == admin_password)
                {
                    cin >> s;
                    status = 4;
                    current_status = "011001";
                    cout << current_status << '\n';
                    break;
                }
                
                if (lock_mode) break;

                status = 5;
                wrong_password_count++;
                if (wrong_password_count == 3) 
                {
                    status = -1;
                    current_status = "110000";
                    cout << current_status << '\n';
                }
                else
                {
                    current_status = "011010";
                    cout << current_status << '\n';
                }

                break;
            }
            case 3: // correct password
            {
                if (s == "X2") 
                {
                    current_status = "011000";
                    cout << current_status << '\n';
                    status = 1;
                }
                else
                {
                    current_status = "011100";
                    cout << current_status << '\n';
                }
                break;
            }
            
            case 4: // admin mode
            {
                if (s[0] != '\"') 
                {
                    current_status = "011001";
                    cout << current_status << '\n';
                    continue;
                }
                vault_password = s.substr(1);
                cin >> s;
                current_status = "011000";
                cout << current_status << '\n';
                break;
            }

            case 5:
            {
                if (s == "X2") 
                {
                    current_status = "011000";
                    cout << current_status << '\n';
                    status = 1;
                }
                else
                {
                    current_status = "011010";
                    cout << current_status << '\n';
                }
                
                break;
            }
            
            case -1:
            {
                if (s == "OFF") 
                {
                    current_status = "000000";
                    cout << current_status << '\n';
                    status = 0;
                }
                else
                {
                    current_status = "110000";
                    cout << current_status << '\n';
                }
            }
        }
    }
}

signed main() 
{
    fastio;
    solve();
    return 0;
}
