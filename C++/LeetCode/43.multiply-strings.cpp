#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> result(400 + 1, 0);
        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                result[i + j] += digit1 * digit2;
            }
        }

        for (int i = 0; i < result.size() - 1; i++)
        {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
        while (result.back() >= 10) 
        {
            int temp = result.back() / 10;
            result.back() %= 10;
            result.push_back(temp);
        }
        while (result.back() == 0 && result.size() > 1)
        {
            result.pop_back();
        }
        
        string resultToString = "";
        for (auto i = result.rbegin(); i != result.rend(); i++)
        {
            resultToString += *i + '0';
        }

        return resultToString;
    }
};
// @lc code=end

