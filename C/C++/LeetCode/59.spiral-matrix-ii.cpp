#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        result.resize(n, vector<int>(n));
        int u = 0, l = 0, d = n - 1, r = n - 1;
        int counter = 1;
        while(counter <= n * n)
        {
            // cout << u << ' ' << d << ' ' << l << ' ' << r << '\n';
            for (int i = l; i <= r; i++)
            {
                result[u][i] = counter;
                counter++;
            }
            u++;
            for (int i = u; i <= d; i++)
            {
                result[i][r] = counter;
                counter++;
            }
            r--;
            for (int i = r; i >= l; i--)
            {
                result[d][i] = counter;
                counter++;
            }
            d--;
            for (int i = d; i >= u; i--)
            {
                result[i][l] = counter;
                counter++;
            }
            l++;
        }

        return result;
    }
};
// @lc code=end

