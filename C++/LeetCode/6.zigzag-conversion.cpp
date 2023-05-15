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
        vector<string> result(numRows, "");

        int status = 0;
        int index = 0;
        int x = 0, y = 0;
        if (numRows == 1)
        {
            for (int i = 0; i < s.length(); i++)
            {
                result[0] += s[i];
            }
        }
        else 
        {
            while (index < s.length())
            {
                result[x] += s[index];
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
            _result += i;
        }

        return _result;
    }
};
// @lc code=end

