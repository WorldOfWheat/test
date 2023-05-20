#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> leftToRight(size, 1);
        vector<int> rightToLeft(size, 1);

        for (int i = 1; i < size; i++)
        {
            if (ratings[i] > ratings[i-1])
            {
                leftToRight[i] = leftToRight[i-1] + 1;
            }
            if (ratings[size - i - 1] > ratings[size - i])
            {
                rightToLeft[size - i - 1] = rightToLeft[size - i] + 1;
            }
        }
        int result = 0;
        for (int i = 0; i < size; i++)
        {
            result += max(leftToRight[i], rightToLeft[i]);
        }
        return result;
    }
};
// @lc code=end

