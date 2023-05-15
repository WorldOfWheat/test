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

        vector<int> result(max(a.size(), b.size()));
        int ptrL = 0;
        int ptrR = 0;
        int index = 0;
        while (ptrL < a.size() && ptrR < b.size())
        {
            result[index] = (a[ptrL] - '0') + (b[ptrR] - '0');
        }
    }
};
// @lc code=end

