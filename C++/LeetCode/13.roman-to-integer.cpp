#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
private:
    map<char, int> roman_to_decimal;

    void init_map()
    {
        roman_to_decimal['I'] = 1;
        roman_to_decimal['V'] = 5;
        roman_to_decimal['X'] = 10;
        roman_to_decimal['L'] = 50;
        roman_to_decimal['C'] = 100;
        roman_to_decimal['D'] = 500;
        roman_to_decimal['M'] = 1000;
    }

public:
    int romanToInt(string s) {
        init_map();

        int result = 0;
        int length = s.length();
        for (int i = 0; i < length; i++)
        {
            char now = s[i];
            switch (now)
            {
                case 'V':
                case 'L':
                case 'D':
                case 'M':
                    result += roman_to_decimal[now];

                    break;

                case 'I':
                case 'X':
                case 'C':
                    if (i + 1 >= length)
                    {
                        result += roman_to_decimal[now];
                        break;
                    }
                    
                    char next = s[i + 1];
                    if (
                        (now == 'I' && (next == 'V' || next == 'X')) ||
                        (now == 'X' && (next == 'L' || next == 'C')) ||
                        (now == 'C' && (next == 'D' || next == 'M'))
                    )
                    {
                        i++;
                        result += roman_to_decimal[next] - roman_to_decimal[now];
                        break;
                    }

                    result += roman_to_decimal[now];

                    break;
            } 
        }

        return result;
    }
};
// @lc code=end

