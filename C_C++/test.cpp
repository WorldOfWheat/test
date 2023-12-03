#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void solve()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    do {
        for (int i = 0; i < arr.size(); i++) cout << arr[i] << endl;
    } while (next_permutation(arr.begin(), arr.end()));
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    solve();

    return 0;
}