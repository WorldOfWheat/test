#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;       
        int result = -1e9;
        map<int, short> ma;
        while (r < s.size()) {
            while (r < s.size() && ma[s[r]] < 1) {
                ma[s[r]]++;
                r++;
            }
            result = max(result, r - l);
            if (l < s.size() && ma[s[l]] == 1) {
                ma[s[l]] = 0;
                l++;
            }
        }
        result = max(result, r - l);
        return result;
    }
};
