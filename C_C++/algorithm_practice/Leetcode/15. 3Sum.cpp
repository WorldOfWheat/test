#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());      

        set<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            int ptrL = i + 1;
            int ptrR = nums.size() - 1;
            while (ptrL < ptrR) {
                int sum = nums[i] + nums[ptrL] + nums[ptrR];
                if (sum > 0) {
                    ptrR--;
                }
                if (sum < 0) {
                    ptrL++;
                }
                if (sum == 0) {
                    vector<int> sub_result(3);
                    sub_result[0] = nums[i];
                    sub_result[1] = nums[ptrL];
                    sub_result[2] = nums[ptrR];
                    result.insert(sub_result);
                    ptrL++;
                }
            }
        }
        
        vector<vector<int>> return_result(result.size());
        int j = 0;
        for (auto i : result) {
            return_result[j++] = i;
        }
        
        return return_result;
    }
};