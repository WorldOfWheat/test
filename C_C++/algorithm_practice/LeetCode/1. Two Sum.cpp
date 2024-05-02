#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_with_index(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            nums_with_index[i].first = nums[i];
            nums_with_index[i].second = i;
        }

        sort(nums_with_index.begin(), nums_with_index.end());

        int ptrL = 0;
        int ptrR = nums_with_index.size() - 1;

        vector<int> result(2);
        while (ptrL < ptrR) {
            int sum = nums_with_index[ptrL].first + nums_with_index[ptrR].first;
            if (sum > target) {
                ptrR--;
            }
            if (sum < target) {
                ptrL++;
            }
            if (sum == target) {
                result[0] = nums_with_index[ptrL].second;
                result[1] = nums_with_index[ptrR].second;
                break;
            }
        }
        
        return result;
    }
};
