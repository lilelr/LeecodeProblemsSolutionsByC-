//
// Created by YuXiao on 5/15/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
// https://leetcode.com/problems/palindrome-partitioning-ii/description/
// 切割字符串，使得每个分割后的字符串段 都是 回文字串，使得切割次数最少？ 动态规划
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42199/My-DP-Solution-(-explanation-and-code)
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int len = s.length();
        vector<vector<bool>> pal(len, vector<bool>(len,false));
        vector<int> dp(len);
        for (int i = len - 1; i >= 0; i--) {
            dp[i] = len - i - 1;
            for (int j = i; j < len; j++) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]==true)) {
                    pal[i][j] = true;
                    if (j == len - 1) {
                        dp[i] = 0;
                    } else if (dp[i] > 1 + dp[j + 1]) {
                        dp[i] = 1 + dp[j + 1];
                    }
                }
            }
        }
        int res = dp[0];
        return res;
    }
};