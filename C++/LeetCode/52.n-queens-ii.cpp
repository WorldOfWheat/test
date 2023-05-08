#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
private:
    int result = 0;
    vector<vector<int>> chessboard;
    vector<pair<int, int>> chessXY;

public:
    void NQueen(int n, int depth)
    {
        if (depth == n)
        {
            result++;
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
                if (abs(j.first - depth) == abs(j.second - i))
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
    int totalNQueens(int n) {
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

