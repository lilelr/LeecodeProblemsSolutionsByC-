#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
// accumulate example
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

using namespace std;

// https://leetcode.com/problems/longest-palindromic-subsequence/description/
// long consecutive subsequence
// dp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        string s_inverse = "";
        for (int i = n - 1; i >= 0; i--) {
            s_inverse += s[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == s_inverse[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[n][n];

    }


};

int main() {

}