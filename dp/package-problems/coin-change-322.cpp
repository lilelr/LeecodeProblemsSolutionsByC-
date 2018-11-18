//
// Created by YuXiao on 3/25/18.
//https://leetcode.com/problems/coin-change/description/
// https://leetcode.com/problems/ones-and-zeroes/discuss/121876/C++-DP-Knapsack-Approach
// 完全背包问题 you have an infinite number of each kind of coin
//
//// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// // 计算满足amount 的最小硬币数量
//Example 1:
//
//Input: coins = [1, 2, 5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
//Example 2:
//
//Input: coins = [2], amount = 3
//Output: -1

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int len = coins.size();
        if (amount < 0) {
            return -1;
        }
        if (len == 0 && amount > 0) {
            return -1;
        }

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;
        for (int i = 0; i < len; i++) { // 选择第i枚硬币
            for (int j = coins[i]; j <= amount; j++) { // 因为硬币无限多，顺序遍历，从j 从小遍历到大
                int &pre = dp[j - coins[i]];
                if (pre != INT_MAX) {
                    dp[j] = min(dp[j], pre + 1); // 计算满足amount 的最小硬币数量,所以用min
                }
//                dp[amount] = min(dp[j-coins[i]])
            }
        }
        int res = dp[amount];
        if (res == INT_MAX) res = -1;
        return res;
    }
};


int main() {
    Solution solution;
    vector<int> coins{1, 2, 5};
    int result = solution.coinChange(coins, 11);

}