#include <bits/stdc++.h>

using namespace std;

string str;
map<string, int> ma;
vector<pair<string, int>> arr;

void solve() {
    while (true) {
        getline(cin, str);
        if (str == "***") {
            break;
        }
        ma[str]++;
    }

    copy(ma.begin(), ma.end(), back_inserter<vector<pair<string, int>>>(arr));
    sort(arr.begin(), arr.end(), [](pair<string, int> x, pair<string, int> y) {
        return x.second < y.second;
    });

    int length = arr.size();
    if (arr[length - 1].second == arr[length - 2].second) {
        cout << "Runoff!" << '\n';
        return;
    }
    cout << arr[length-1].first << '\n';
}

int main() {
    solve();

    return 0;
}