#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.resize(1 << n);
        for (int i = 0; i < (1 << n); i++)
        {
            result[i] = i;
            result[i] ^= result[i] >> 1;
        }
        
        return result;
    }
};
// @lc code=end

