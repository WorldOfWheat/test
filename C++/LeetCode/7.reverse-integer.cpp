#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int absX = abs(x);

        string reversed = to_string(absX);
        std::reverse(reversed.begin(), reversed.end());
        long long result = 0;
        for (auto i : reversed)
        {
            result *= 10;
            result += i - '0';
            if (
                ((x < 0) && (-result < -((long long) 1 << 31))) || 
                ((x >= 0) && (result > ((long long) 1 << 31) - 1))
            )
            {
                return 0;
            }
        }
        if (x < 0)
        {
            result *= -1;
        }

        return result;
    }
};
// @lc code=end

