#include <iostream>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    string str[n];

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    string ans = "";
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = 0; j < m; j++) {
            if (str[i][j] != '#') {
                temp = temp + str[j];
                continue;
            }
            if (temp.length() >= 2) {
                if (ans == "") {
                    ans = temp;
                    temp = "";
                    continue;
                }
                if (ans < temp) {
                    ans = temp;
                }
                temp = "";
            }
        }
    }

    for (int i = 0; i < m; i++) {
        string temp = "";
        for (int j = 0; j < n; j++) {
            if (str[j][i] != '#') {
                temp = temp + str[j];
                continue;
            }
            if (temp.length() >= 2) {
                if (ans == "") {
                    ans = temp;
                    temp = "";
                    continue;
                }
                if (ans <= temp) {
                    ans = temp;
                }
                temp = "";
            }
        }
    }

    cout << ans << "\n";

    return 0;

}