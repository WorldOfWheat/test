#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
    vector<string> letterMapping = 
    {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void getCombinations(int index, string digits, string current)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }

        string letters = letterMapping[digits[index] - '0' - 1];
        for (int i = 0; i < letters.size(); i++)
        {
            getCombinations(index + 1, digits, current + letters[i]);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return this->result;
        }

        getCombinations(0, digits, "");

        return this->result;
    }
};
// @lc code=end

