#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<9> numberCheck(0);
        int l = 0;
        int u = 0;
        while (true)
        {
            numberCheck.reset();
            for (int i = l; i < l + 3; i++)
            {
                for (int j = u; j < u + 3; j++)
                {
                    char num = board[i][j];
                    if (num == '.')
                    {
                        continue;
                    }
                    num -= '0';
                    if (numberCheck[num])
                    {
                        return false;
                    }
                    numberCheck[num] = 1;
                }
            }
            l += 3;
            if (l == 9)
            {
                l = 0;
                u += 3;
            }
            if (u == 9)
            {
                break;
            }
        }
    }
};
// @lc code=end

