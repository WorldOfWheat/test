#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 1)
        {
            return strs[0];
        }

        int index = 0;
        while (true)
        {
            bool flag = true;
            for (int i = 0; i < strs.size() - 1; i++)
            {   
                if (index >= strs[i].length())
                {
                    flag = false;
                    break;
                }
                if (strs[i][index] != strs[i + 1][index])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                string result = strs[0].substr(0, index);
                return result;
            }
            index++;
        }
    }
};
// @lc code=end

