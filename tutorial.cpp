#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int arr[n];
        double sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        sum /= n;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > sum) {
                cnt++;
            }
        }
        cout << fixed << setprecision(3) << ((double) cnt / n * 100) << "%" << "\n";
    }    

    return 0;

}