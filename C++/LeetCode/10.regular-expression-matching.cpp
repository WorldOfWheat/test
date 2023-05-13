#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        vector<vector<bool>> dp(p_size, vector<bool>(p_size));

        dp[0][0] = true;

        for (int i = 1; i <= s_size)
        {
            for (int j = 1; j <= p_size)
            {
                if (p[j] == '*')
                {
                    dp[i][j] = dp[i][j]
                }
            }
        }
    }
};
// @lc code=end

