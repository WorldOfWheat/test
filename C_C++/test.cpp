#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define debug(container) for (auto i : container) cerr << i << ' '; cerr << '\n';

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;
int m;

void solve()
{
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    
    cin >> m;
    for (int i = 0; i < m; i++) 
    {
        char a, b;
        cin >> a >> b;
        pii num1, num2, num3;

        // x
        if (a == '%')
        {
            num2 = arr.back();

            int l = 0, r = arr.size();
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (arr[mid].first < num2.first) l = mid;
                else r = mid - 1;
            }
            num1 = arr[l];
        }
        else 
        {
            num1 = arr.back();
            if (a == '+' || a== '*') num2 = num1;
            else num2 = arr.front();
        }
        // y
        if (b == '+' || b == '*') num3 = arr.back();
        else num3 = arr.front();
        
        cout << num1.second << ' ' << num2.second << ' ' << num3.second << '\n';
    }
}


int main()
{
    fastio;
    solve();
    return 0;
}