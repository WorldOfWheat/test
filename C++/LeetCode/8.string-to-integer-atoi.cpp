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
        int index = 0;
        long long result = 0;
        int sign = 1;
        while (s[index] == ' ' || s[index] == '_')
        {
            index++;
        }
        if (s[index] == '-' || s[index] == '+')
        {
            if (s[index] == '-')
            {
                sign = -1;
            }
            index++;
        }
        const int clampMin = -((long long) 1 << 31);
        const int clampMax = ((long long) 1 << 31) - 1;
        for (int i = index; i < s.length(); i++)
        {
            if (!isdigit(s[i]))
            {
                break;
            }
            result *= 10;
            if (sign == 1)
            {
                result += s[i] - '0';
                if (result >= clampMax)
                {
                    result = clampMax;
                    break;
                }
            }
            else
            {
                result -= s[i] - '0';
                if (result <= clampMin)
                {
                    result = clampMin;
                    break;
                }
            }
        }

        return result;
    }
};
// @lc code=end
