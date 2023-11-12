#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> arr;
vector<int> arr2;

void solve()
{
    cin >> n >> m;

    arr.resize(n + 2);
    arr2.resize(n + 1);

    arr[0] = 1e9;
    for (int i = 0; i < n; i++) 
    {
        int a;
        cin >> a;
        arr2[i + 1] = a;
        arr[a] = i + 1;
    }
    arr.push_back(1e9);

    // for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    // cout << '\n';

    int start = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] < arr[i - 1]) start++;
    }

    int current = start;
    while (m--)
    {
        bool last_a = false, last_b = false, last_c = false, last_d = false;
        bool current_a = false, current_b = false, current_c = false, current_d = false;

        int a, b;
        cin >> a >> b;

        int index_a = arr2[a];
        int index_b = arr2[b];
        if (index_a > index_b) swap(index_a, index_b);
        if (arr[index_a] < arr[index_a-1]) last_a = true;
        if (arr[index_b] < arr[index_b-1]) last_b = true;
        if (arr[index_b+1] < arr[index_b]) last_c = true;
        if (abs(index_a - index_b) > 1) 
        {
            if (arr[index_a+1] < arr[index_a]) last_d = true;
        }
        // cout << '#' << arr[index_b+1] << ' ' << arr[index_b] << "\n";
        swap(arr2[a], arr2[b]);
        swap(arr[index_a], arr[index_b]);
        if (arr[index_a] < arr[index_a-1]) current_a = true;
        if (arr[index_b] < arr[index_b-1]) current_b = true;
        if (arr[index_b+1] < arr[index_b]) current_c = true;
        if (abs(index_a - index_b) > 1) 
        {
            if (arr[index_a+1] < arr[index_a]) current_d = true;
        }
        // cout << '#' << arr[index_b+1] << ' ' << arr[index_b] << "\n";

        // for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
        // cout << '\n';
        // cout << last_a << ' ' << last_b << ' ' << last_c << '\n';
        // cout << current_a << ' ' << current_b << ' ' << current_c << '\n';

        if (!last_a && current_a) current++;
        else if (last_a && !current_a) current--;

        if (!last_b && current_b) current++;
        else if (last_b && !current_b) current--;

        if (!last_c && current_c) current++;
        else if (last_c && !current_c) current--;

        if (abs(index_a - index_b) > 1) 
        {
            if (!last_d && current_d) current++;
            else if (last_d && !current_d) current--;
        }

        cout << current << "\n";
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