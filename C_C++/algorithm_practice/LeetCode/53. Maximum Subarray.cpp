#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int l, int r) {
        if (l + 1 >= r) {
            return arr[l];
        }
        
        int mid = (l + r) >> 1;
        int left_part = solve(arr, l, mid);
        int right_part = solve(arr, mid, r);
        
        int right_current_sum = 0;
        int maximum_right_sum = -1e9;
        for (int i = mid; i < r; i++) {
            right_current_sum += arr[i];
            maximum_right_sum = max(maximum_right_sum, right_current_sum);
        }
        int left_current_sum = 0;
        int maximum_left_sum = -1e9;
        for (int i = mid - 1; i >= l; i--) {
            left_current_sum += arr[i];
            maximum_left_sum = max(maximum_left_sum, left_current_sum);
        }
        int mid_part = max({maximum_left_sum, maximum_right_sum, maximum_left_sum + maximum_right_sum});
        
        return max({left_part, mid_part, right_part});
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size());
    }
};