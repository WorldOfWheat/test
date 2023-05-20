#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
struct DP_data
{
    int from;
    char data;
};

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        string rs = s; 
        reverse(rs.begin(), rs.end());

        vector<vector<DP_data>> dp;
        dp.resize(length + 1, vector<DP_data>(length + 1));

        for (int i = 1; i <= length; i++)
        {
            for (int j = 1; j <= length; j++)
            {
                if (s[i-1] != rs[j-1])
                {
                    if (dp[i-1][j].data > dp[i][j-1].data)
                    {
                        dp[i][j].data = dp[i-1][j].data + 1;
                        dp[i][j].from = 1;
                    }
                    else
                    {
                        dp[i][j].data = dp[i][j-1].data + 1;
                        dp[i][j].from = 2;
                    }
                    continue;
                }
                
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
};
// @lc code=end

