#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
private:
    vector<vector<char>> board;
    vector<pair<int, int>> emptyBlock;
    bitset<10> checked;
    bitset<10> checked2;

    bool check(int x, int y)
    {
        checked.reset();
        checked2.reset();
        for (int i = 0; i < 9; i++)
        {
            if (board[x][i] != '.')
            {
                int num = board[x][i] - '0';
                if (checked[num])
                {
                    return false;
                }
                checked[num] = 1;
            }
            if (board[i][y] != '.')
            {
                int num = board[i][y] - '0';
                if (checked2[num])
                {
                    return false;
                }
                checked2[num] = 1;
            }
        }

        checked.reset();
        int u = (x / 3) * 3;
        int l = (y / 3) * 3;
        for (int i = u; i < u + 3; i++)
        {
            for (int j = l; j < l + 3; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int num = board[i][j] - '0';
                if (checked[num])
                {
                    return false;
                }
                checked[num] = 1;
            }
        }

        return true;
    }

    bool solve(int index)
    {
        if (index == emptyBlock.size())
        {
            return true;
        }

        auto block = emptyBlock[index];
        for (int i = 1; i <= 9; i++)
        {
            board[block.first][block.second] = i + '0';
            if (!check(block.first, block.second))
            {
                continue;
            }
            if (solve(index+1))
            {
                return true;
            }
            board[block.first][block.second] = '.';
        }
        board[block.first][block.second] = '.';

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    emptyBlock.push_back({i, j});
                }
            }
        }
        this->board = board;

        if (solve(0)) 
        {
            board = this->board;
        }
    }
};
// @lc code=end

