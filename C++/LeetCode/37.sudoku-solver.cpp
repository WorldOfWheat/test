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
    vector<bitset<10>> columns;
    vector<bitset<10>> rows;
    vector<vector<bitset<10>>> bigBlock;

    bool solve(int index)
    {
        if (index == emptyBlock.size())
        {
            return true;
        }

        auto block = emptyBlock[index];
        for (int i = 1; i <= 9; i++)
        {
            if (!(
                columns[block.first][i] != 1 && 
                rows[block.second][i] != 1 && 
                bigBlock[block.first / 3][block.second / 3][i] != 1
                )
            )
            {
                continue;
            }

            columns[block.first][i] = 1;
            rows[block.second][i] = 1;
            bigBlock[block.first / 3][block.second / 3][i] = 1;
            board[block.first][block.second] = i + '0';
            if (solve(index+1))
            {
                return true;
            }
            columns[block.first][i] = 0;
            rows[block.second][i] = 0;
            bigBlock[block.first / 3][block.second / 3][i] = 0;
            board[block.first][block.second] = '.';
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        columns.resize(9, bitset<10>());
        rows.resize(9, bitset<10>());
        bigBlock.resize(3);
        for (auto &i : bigBlock)
        {
            i.resize(3, bitset<10>());
        }

        int u = 0, l = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    emptyBlock.push_back({i, j});
                    continue;
                }
                columns[i][board[i][j] - '0'] = 1;
                rows[j][board[i][j] - '0'] = 1;
            }

            for (int j = u * 3; j < u * 3 + 3; j++)
            {
                for (int k = l * 3; k < l * 3 + 3; k++)
                {
                    if (board[j][k] == '.')
                    {
                        continue;
                    }
                    bigBlock[u][l][board[j][k] - '0'] = 1;
                }
            }
            l++;
            if (l == 3)
            {
                u++;
                l = 0;
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