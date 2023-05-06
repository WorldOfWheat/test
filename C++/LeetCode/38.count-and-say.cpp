#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        {
            return "1";
        }

        string result = countAndSay(n - 1);
        char lastChar;
        int count = 0;
        for (int i = 0; i < result.length(); i++)
        {
            if (i == 0)
            {
                lastChar = result[i];
                continue;
            }
            if (lastChar != result[i])
            {
                
            }
        }
    }
};
// @lc code=end

