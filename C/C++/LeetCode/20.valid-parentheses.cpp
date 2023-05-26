#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        vector<char> stackL; 
        vector<char> stackR;
        for (auto i : s)
        {
            stackL.push_back(i);
        }
        while (stackL.size())
        {
            char back = stackL.back();
            if (stackR.empty())
            {
                stackR.push_back(back);
                stackL.pop_back();
                continue;
            }
            char front = stackR.back();
            if ((back == '(' && front == ')') || 
                (back == '{' && front == '}') ||
                (back == '[' && front == ']'))
            {
                stackL.pop_back();
                stackR.pop_back();
                continue;
            }
            stackR.push_back(back);
            stackL.pop_back();
        }
        
        return stackR.size() == 0;
    }
};
// @lc code=end

