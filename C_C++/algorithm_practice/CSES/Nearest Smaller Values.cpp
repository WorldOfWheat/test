#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
stack<pii> st;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        while (st.size() && st.top().first >= a) st.pop();

        if (st.empty())
            cout << '0' << ' ';
        else
            cout << st.top().second << ' ';

        st.push({a, i + 1});
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}