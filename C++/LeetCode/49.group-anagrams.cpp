#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (auto i : strs)
        {
            string temp = i;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> result;
        for (auto i : mp)
        {
            result.push_back(i.second);
        }

        return result;
    }
};
// @lc code=end

