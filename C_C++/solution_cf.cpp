#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int t1, t2;
vector<pair<string, int>> arr;
vector<string> arr2; 

void solve()
{
    cin >> t1;
    int counter = 0;
    while (t1--)
    {
        string str;
        cin >> str;
        string phone_number_with_extension = "";
        for (int i = 0; i < 10; i++)
        {
            phone_number_with_extension += str[i];
        }
        for (int i = 10 + 2; i < str.length() - 8; i++)
        {
            if (str[i] != '-' && str[i] != '>')
            {
                phone_number_with_extension += str[i];
            }
        } 

        string name = "";
        for (int i = str.length() - 8; i < str.length(); i++)
        {
            name += str[i];
        }
        arr.push_back({name, counter++});
        arr2.push_back(phone_number_with_extension);
    }

    sort(arr.begin(), arr.end());

    cin >> t2;
    while (t2--)
    {
        string str;
        cin >> str;
        auto it = lower_bound(arr.begin(), arr.end(), make_pair(str, 0));
        int index = (*it).second;
        cout << (arr2[index]) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}