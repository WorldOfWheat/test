#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
private:
    map<char, int> charRecord;
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        int result = 0;
        int i = 0;
        for (int j = 0; j < length; j++)
        {
            while (charRecord[s[j]] != 0)
            {
                charRecord[s[i]]--;
                i++;
            }
            charRecord[s[j]]++;
            result = max(result, j - i + 1);
        }

        return result;
    }
};
// @lc code=end

