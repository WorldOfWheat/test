#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        vector<int> result;
        int ptrL = 0;
        int ptrR = 0;
        int index = 0;
        while (ptrL < a.size() && ptrR < b.size())
        {
            result.push_back((a[ptrL++] - '0') + (b[ptrR++] - '0'));
            if (result.back() >= 2)
            {
                int temp = result.back();
                result.back() -= 2;
                result.push_back(temp / 2);
            }
        }
        if (result.back() >= 2)
        {
            result.back() -= 2;
            result.push_back(1);
        }
        while (ptrL < a.size())
        {
            result.push_back((a[ptrL++] - '0'));
        }
        while (ptrR < b.size()) 
        {
            result.push_back((b[ptrR++] - '0'));
        }

        string _result = "";
        for (auto i = result.rbegin(); i != result.rend(); i++)
        {
            _result += (*i) + '0';
        }
        return _result;
    }
};
// @lc code=end

