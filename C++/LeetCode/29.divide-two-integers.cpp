#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long result = (long long) dividend / (long long) divisor;
        const long long clampMax = (1 << 31) - 1;
        const long long clampMin = -(1 << 31);
        result = max(result, clampMin);
        result = min(result, clampMax);

        return result;
    }
};
// @lc code=end

