#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string integerToString = to_string(x);
        int length = integerToString.length();
        int ptrL = 0, ptrR = length - 1;
        while (ptrL < ptrR) {
            if (integerToString[ptrL] != integerToString[ptrR]) {
                return false;
            }
            ptrL++;
            ptrR--;
        }
        return true;
    }
};
// @lc code=end

