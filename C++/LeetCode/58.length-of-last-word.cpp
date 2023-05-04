#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start

class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());

        int ptrL = 0, ptrR = 0;
        while (s[ptrL] == ' ')
        {
            ptrL++;
            ptrR++;
        }
        while (ptrR <= s.length() && s[ptrR] != ' ')
        {
            ptrR++;
        }

        string lastWord = s.substr(ptrL, ptrR - ptrL);

        return lastWord.length();
    }
};
// @lc code=end

