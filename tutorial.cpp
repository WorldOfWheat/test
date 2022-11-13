#include <iostream>

using namespace std;

int nums[20][20];
int prefixSum[20 + 1][20 + 1];

int main() {

    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefixSum[i][j] = (prefixSum[i-1][j] - prefixSum[i-1][j-1]) + prefixSum[i][j-1] + nums[i-1][j-1];
        }
    }
    
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int o = i; o <= n; o++) {
                for (int k = j; k <= n; k++) {
                    int sum = prefixSum[o][k] - prefixSum[o][j-1] - prefixSum[i-1][k] + prefixSum[i-1][j-1];
                    if (sum > maxi) {
                        maxi = sum;
                    }
                }
            }
        }
    }

    cout << maxi << '\n';

    return 0;

}