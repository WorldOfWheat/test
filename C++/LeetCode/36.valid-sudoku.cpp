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
        bitset<10> numberCheck(0);
        int l = 0;
        int u = 0;
        while (true)
        {
            numberCheck.reset();
            for (int i = l; i < l + 3; i++)
            {
                for (int j = u; j < u + 3; j++)
                {
                    if (board[i][j] == '.')
                    {
                        continue;
                    }
                    int num = board[i][j] - '0';
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
        for (int i = 0; i < 9; i++)
        {
            numberCheck.reset();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int num = board[i][j] - '0' - 1; 
                if (numberCheck[num])
                {
                    return false;
                }
                numberCheck[num] = 1;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            numberCheck.reset();
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                {
                    continue;
                }
                int num = board[j][i] - '0'; 
                if (numberCheck[num])
                {
                    return false;
                }
                numberCheck[num] = 1;
            }
        }
        
        return true;
    }
};
// @lc code=end

