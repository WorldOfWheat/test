#include <iostream>

using namespace std;

int arr[26+1];

int main() {

    string str, str2;
    cin >> str >> str2;

    string res = "";
    string temp = "";

    for (int i = 0; i < str2.length(); i++) {
        temp += str[i] - (str2[i] - 'A');
    }

    res += temp;

    for (int i = str2.length(); i < str.length();) {
            
    }
    cout << res << "\n";

    return 0;

}