// https://leetcode.com/problems/ones-and-zeroes/description/
// 三维0-1 背包问题
// https://leetcode.com/problems/ones-and-zeroes/discuss/121876/C++-DP-Knapsack-Approach
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef vector<int> v1d;
typedef vector<v1d> v2d;
typedef vector<v2d> v3d;

class Solution {
public:
    /**
     *
     * @param strs
     * @param m zeroes
     * @param n ones
     * @return 最多能组合成的strs 中的数量
     */
    int findMaxForm(vector<string> &strs, int m, int n) {
        int len = strs.size();

        v3d dp(len + 1, v2d(m + 1, v1d(n + 1, 0)));

        for (int i = 1; i <= len; i++) {
            string s = strs[i - 1];
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.size() - ones;

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - zeros][k - ones]);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }// k
            }// j
        }// i

        return dp[len][m][n];

    }


//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//
//        for (auto &s: strs) {
//            int ones = count(s.begin(), s.end(), '1');
//            int zeros= s.size()-ones;
//            for (int i=m; i>=zeros; i--)
//                for (int j=n; j>=ones; j--)
//                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
//        }
//        return dp[m][n];
//    }

};


int main() {

}