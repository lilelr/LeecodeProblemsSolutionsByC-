//https://leetcode.com/problems/coin-change-2/description/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/coin-change-2/description/
// 背包问题 ， 计算满足amount 的解法总数
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        if (amount == 0) return 1;
        int n = coins.size();

        if (n == 0) return 0;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 初始化时，dp[0] = 1
        for (int i = 0; i < n; i++) { // 第i枚银币，
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i]) {
                    dp[j] = dp[j] + dp[j - coins[i]];
                }
            }
        }

        int res = dp[amount];
        return res;
    }

};


int main() {

}