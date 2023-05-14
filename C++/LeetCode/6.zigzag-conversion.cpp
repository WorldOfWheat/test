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
        vector<vector<char>> result(numRows, vector<char>(s.length()));
        int status = 0;
        int index = 0;
        int x = 0, y = 0;
        while (index < s.length())
        {
            result[x][y] = index;
            if (status == 0)
            {
                x++;
                if (x == numRows)
                {
                    x--;
                    status = 1;
                }
            }
            if (status == 1)
            {
                x--;
                y++;
                if (x < 0)
                {
                    x++;
                    y--;
                    status = 0;
                }
            }

            index++;
        }

        string _result = "";
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                _result += result[i][j];
            }
            _result += "\n";
        }

        return _result;
    }
};
// @lc code=end

