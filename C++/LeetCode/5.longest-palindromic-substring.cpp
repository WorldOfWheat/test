#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> dp;

public:
    string longestPalindrome(string s) {
        int length = s.length();
        string rS = s; 
        reverse(rS.begin(), rS.end());
        dp.resize(length, vector<int>(length));

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {

            }
        }
    }
};
// @lc code=end

