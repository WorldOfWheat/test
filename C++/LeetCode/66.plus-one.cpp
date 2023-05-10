#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int index = 0;
        digits[index]++;
        while (digits[index] >= 10 && index + 1 < digits.size())
        {
            digits[index + 1] += digits[index] / 10;
            digits[index] %= 10;
            index++;
        }
        while (digits.back() >= 10)
        {
            int temp = digits.back();
            digits.back() %= 10;
            digits.push_back(temp / 10);
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};
// @lc code=end

