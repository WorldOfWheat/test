#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int index = 1;
        while (index < intervals.size())
        {
            vector<int> temp = result.back();
            vector<int> temp2 = intervals[index];

            if (temp[0] >= temp2[0] && temp[1] <= temp2[1])
            {
                result.back() = intervals[index];
            }
            else if (temp[1] >= temp2[0] && temp[1] <= temp2[1])
            {
                result.back()[1] = intervals[index][1];
            }
            else if (!(temp[0] <= temp2[0] && temp[1] >= temp2[1]))
            {
                result.push_back(intervals[index]);
            }
            index++;
        }

        return result;
    }
};
// @lc code=end

