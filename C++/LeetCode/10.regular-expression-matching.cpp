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
        vector<vector<bool>> dp(s_size + 1, vector<bool>(p_size + 1));

        dp[0][0] = true;
        for (int j = 1; j <= p_size; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= s_size; i++)
        {
            for (int j = 1; j <= p_size; j++)
            {
                if (p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2];
                    if (s[i-1] == p[j-2] || p[j-2] == '.')
                    {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                    continue;
                }
                if (s[i-1] == p[j-1] || p[j-1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[s_size][p_size];
    }
};
// @lc code=end

