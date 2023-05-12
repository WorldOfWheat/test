#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
private:
    map<int, string> decimalToRoman = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

public:
    string intToRoman(int num) {
        string result = "";
        int level = 1000;
        int minusLevel = 100;
        int index = 0;
        while (num > 0)
        {
            while (num >= level)
            {
                result += decimalToRoman[level];
                num -= level;
            }
            int temp = level - minusLevel; 
            if (num >= temp)
            {
                result += decimalToRoman[temp];
                num -= temp;
            }

            if (index % 2 == 0)
            {
                level /= 2;
            }
            else
            {
                level /= 5;
                if (index >= 1)
                {
                    minusLevel /= 10;
                }
            }
            index++;
        }

        return result;
    }
};
// @lc code=end


