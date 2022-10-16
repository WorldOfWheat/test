#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mini = 99999999;
    int ans;

    for (int i = 0; i < n; i++) {
        if (mini > arr[i]) {
            ans = i;
            mini = arr[i];
        }
    }

    cout << ans << "\n";

    return 0;

}