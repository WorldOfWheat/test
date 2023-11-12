#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

class Solution {
public:
    string longestPalindrome(string s) {
        string reverse_s = s;
        reverse(s.begin(), s.end());

        vector<vector<int>> lcs;
        vector<vector<int>> path;

        lcs.resize(s.size() + 1, vector<int>(s.size() + 1));
        path.resize(s.size() + 1, vector<int>(s.size() + 1));

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (s[i-1] == reverse_s[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                    path[i][j] = 2;
                    continue;
                }
                if (lcs[i-1][j] > lcs[i][j-1]) {
                    lcs[i][j] = lcs[i-1][j]; 
                    path[i][j] = 1;
                } else {
                    lcs[i][j] = lcs[i][j-1]; 
                    path[i][j] = 3;
                }
            }
        }

        int now_y;
        int maximum = -1e9;
        for (int i = 1; i <= s.size(); i++) {
            if (lcs[s.size()][i] > maximum) {
                now_y = i;
                maximum = lcs[s.size()][i];
            }
        }

        string result = "";
        int now_x = s.size();
        while (now_x != 0 && now_y != 0) {
            if (path[now_x][now_y] == 1) {
                now_y--;
                continue;
            }
            if (path[now_x][now_y] == 3) {
                now_x--;
                continue;
            }
            if (path[now_x][now_y] == 2) {
                result += s[now_y - 1];
                now_x--;
                now_y--;
            }
        }

        return result;
    }
};
// @lc code=end

