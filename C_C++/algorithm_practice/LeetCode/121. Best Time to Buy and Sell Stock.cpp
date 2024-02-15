#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_minimum = 1e5;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - current_minimum);
            current_minimum = min(current_minimum, prices[i]);
        }
        return ans;
    }
};