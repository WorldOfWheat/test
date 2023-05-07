#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '-' || ch == '+')
            {
                if (i + 1 >= s.length())
                {
                    continue;
                }
                if (ch == '-')
                {
                    sign = -1;
                    continue;
                }
                if (ch == '+')
                {
                    sign = 1;
                    continue;
                }
            }
            if (!isdigit(ch))
            {
                continue;
            }
            result *= 10;
            result += ch - '0';
        }
        result *= sign;
        result = max(result, -((long long) 1 << 31));
        result = min(result, ((long long) 1 << 31) - 1);

        return result;
    }
};
// @lc code=end

