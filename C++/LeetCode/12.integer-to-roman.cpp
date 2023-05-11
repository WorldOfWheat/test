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
    map<int, char> decimalToRoman = {
        {1000, 'M'},
        {500, 'D'},
        {100, 'C'},
        {50, 'L'},
        {10, 'X'},
        {5, 'V'},
        {1, 'I'},
    };

public:
    string intToRoman(int num) {
        int index = 0;
        int level = 1000;
        string result = "";

        while (num > 0)
        {
            while (num >= level)
            {
                
            }
        }
    }
};
// @lc code=end


