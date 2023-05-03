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
        vector<bitset<16>> bsArray;
        bsArray.resize(1 << n);
        for (int i = 0; i < (1 << n); i++)
        {
            bsArray[i] = i;
            for (int j = 14; j >= 0; j--)
            {
                bsArray[i][j] = bsArray[i][j+1] != bsArray[i][j];
            }
        }
        
        vector<int> result;
        for (int i = 0; i < 1 << n; i++)
        {
            result.emplace_back((int) bsArray[i].to_ulong());
        }
        return result;
    }
};
// @lc code=end

