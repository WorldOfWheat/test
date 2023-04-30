#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> arr;

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--)
    {
        while (true)
        {
            string input;
            cin >> input;
            if (input == "*")
            {
                break;
            }
            arr.emplace_back(input);
        }
        
        sort(arr.begin(), arr.end());

        string start, end;
        cin >> start >> end;

        
    }


    return 0;
}