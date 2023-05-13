#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> candidates;

    void calculate(vector<int> combination, int index, int sum, int target)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            result.push_back(combination);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            combination.push_back(candidates[i]);
            calculate(combination, i, sum + candidates[i], target);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;

        vector<int> carrier;
        calculate(carrier, 0, 0, target);

        return result;
    }
};
// @lc code=end

