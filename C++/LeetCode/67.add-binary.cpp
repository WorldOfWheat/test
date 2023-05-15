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

        string result;
        int carry = 0;
        int ptrL = 0;
        int ptrR = 0;
        while (ptrL < a.size() && ptrR < b.size())
        {
            int digit1 = (a[ptrL++] - '0'); 
            int digit2 = (b[ptrR++] - '0'); 
            result += (digit1 ^ digit2 ^ carry) + '0';
            carry = (digit1 && digit2) || (digit1 && carry) || (digit2 && carry);
        }
        while (ptrL < a.size())
        {
            int digit1 = (a[ptrL++] - '0'); 
            result += (digit1 ^ carry) + '0';
            carry = (carry && digit1);
        }
        while (ptrR < b.size())
        {
            int digit1 = (b[ptrR++] - '0'); 
            result += (digit1 ^ carry) + '0';
            carry = (carry && digit1);
        }
        if (carry == 1)
        {
            result += carry + '0';
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end

