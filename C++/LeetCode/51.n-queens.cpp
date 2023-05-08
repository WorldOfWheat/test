#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> chessboard;
    vector<pair<int, int>> chessXY;
    vector<vector<string>> result;

public:
    void saveChessboard(int n)
    {
        vector<string> _result;
        for (int i = 0; i < n; i++)
        {
            string row = "";
            for (int j = 0; j < n; j++)
            {
                if (chessboard[i][j] == 1)
                {
                    row += 'Q';
                    continue;
                }
                row += '.';
            }
            _result.push_back(row);
        }
        this->result.push_back(_result);
    }

    void NQueen(int n, int depth)
    {
        if (depth == n)
        {
            saveChessboard(n);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < depth; j++)
            {
                if (chessboard[j][i] == 1)
                {
                    goto skip;
                }
            }
            for (auto j : chessXY)
            {
                if (j.first - depth == j.second - i)
                {
                    goto skip;
                }
            }

            chessboard[depth][i] = 1;
            chessXY.push_back({depth, i});
            NQueen(n, depth + 1);
            chessXY.pop_back();
            chessboard[depth][i] = 0;

            skip:
            continue;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        chessboard.resize(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            chessboard[0][i] = 1;
            chessXY.push_back({0, i});
            NQueen(n, 1);
            chessXY.pop_back();
            chessboard[0][i] = 0;
        }

        return result;
    }
};
// @lc code=end

