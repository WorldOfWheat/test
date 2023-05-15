#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<int>> result(numRows, vector<int>(s.length()));

        int status = 0;
        int index = 0;
        int x = 0, y = 0;
        if (numRows == 1)
        {
            for (int i = 0; i < s.length(); i++)
            {
                result[0][i] = s[i] - '0';
            }
        }
        else 
        {
            while (index < s.length())
            {
                result[x][y] = s[index] - '0';
                if (status == 0)
                {
                    x++;
                    if (x == numRows)
                    {
                        x-=2;
                        y++;
                        status = 1;
                    }
                }
                else if (status == 1)
                {
                    x--;
                    y++;
                    if (x < 0)
                    {
                        x+=2;
                        y--;
                        status = 0;
                    }
                }

                index++;
            }
        }

        string _result = "";
        for (auto i : result)
        {
            for (auto j : i)
            {
                if (j == 0)
                {
                    continue;
                }
                _result += j + '0';
            }
        }

        return _result;
    }
};
// @lc code=end

